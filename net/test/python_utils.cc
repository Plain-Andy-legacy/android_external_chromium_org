// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "net/test/python_utils.h"

#include "base/base_paths.h"
#include "base/command_line.h"
#include "base/environment.h"
#include "base/files/file_path.h"
#include "base/files/file_util.h"
#include "base/logging.h"
#include "base/memory/scoped_ptr.h"
#include "base/path_service.h"
#include "base/strings/utf_string_conversions.h"

const char kPythonPathEnv[] = "PYTHONPATH";

void AppendToPythonPath(const base::FilePath& dir) {
  scoped_ptr<base::Environment> env(base::Environment::Create());
  std::string old_path;
  std::string dir_path;
#if defined(OS_WIN)
  dir_path = base::WideToUTF8(dir.value());
#elif defined(OS_POSIX)
  dir_path = dir.value();
#endif
  if (!env->GetVar(kPythonPathEnv, &old_path)) {
    env->SetVar(kPythonPathEnv, dir_path.c_str());
  } else if (old_path.find(dir_path) == std::string::npos) {
    std::string new_path(old_path);
#if defined(OS_WIN)
    new_path.append(";");
#elif defined(OS_POSIX)
    new_path.append(":");
#endif
    new_path.append(dir_path.c_str());
    env->SetVar(kPythonPathEnv, new_path);
  }
}

namespace {

#if defined(OS_MACOSX) || defined(OS_CHROMEOS)
// Search for |to_try|, rolling up the directory tree from
// |start_dir|.  If found, return true and put the path to |to_try| in
// |out_dir|.  If not, return false and leave |out_dir| untouched.
bool TryRelativeToDir(const base::FilePath& start_dir,
                      const base::FilePath& to_try,
                      base::FilePath* out_dir) {
  base::FilePath dir(start_dir);
  while (!base::DirectoryExists(dir.Append(to_try))) {
    base::FilePath parent = dir.DirName();
    if (parent == dir) {
      // We hit the root directory.
      return false;
    }
    dir = parent;
  }
  *out_dir = dir;
  return true;
}
#endif  // defined(OS_MACOSX) || defined(OS_CHROMEOS)

}  // namespace

bool GetPyProtoPath(base::FilePath* dir) {
  // Locate the Python code generated by the protocol buffers compiler.
  base::FilePath generated_code_dir;
  if (!PathService::Get(base::DIR_EXE, &generated_code_dir)) {
    LOG(ERROR) << "Can't find " << generated_code_dir.value();
    return false;
  }

  const base::FilePath kPyProto(FILE_PATH_LITERAL("pyproto"));

#if defined(OS_MACOSX) || defined(OS_CHROMEOS)
  base::FilePath source_dir;
  if (!PathService::Get(base::DIR_SOURCE_ROOT, &source_dir)) {
    LOG(ERROR) << "Can't find " << source_dir.value();
    return false;
  }
  // On Mac, and possibly Chrome OS, DIR_EXE might be pointing deep
  // into the Release/ (or Debug/) directory and we can't depend on
  // how far down it goes. So we walk upwards from DIR_EXE until we
  // find a likely looking spot.
  if (!TryRelativeToDir(generated_code_dir, kPyProto, dir)) {
    LOG(WARNING) << "Can't find " << kPyProto.value()
                 << " next to " << generated_code_dir.value();
    // On Chrome OS, we may have installed the test binaries and support tools
    // in a wholly separate location, relative to DIR_SOURCE_ROOT.  We'll want
    // to do a similar investigation from that point as well.
    generated_code_dir = source_dir
        .Append(FILE_PATH_LITERAL("out"))
        .Append(FILE_PATH_LITERAL("Release"));
    if (!TryRelativeToDir(generated_code_dir, kPyProto, dir)) {
      LOG(WARNING) << "Can't find " << kPyProto.value()
                   << " next to " << generated_code_dir.value();
      return false;
    }
  }
  generated_code_dir = *dir;
#endif
  *dir = generated_code_dir.Append(kPyProto);
  VLOG(2) << "Found " << kPyProto.value() << " in " << dir->value();
  return true;
}

bool GetPythonCommand(base::CommandLine* python_cmd) {
  DCHECK(python_cmd);

  python_cmd->SetProgram(base::FilePath(FILE_PATH_LITERAL("python")));

  // Launch python in unbuffered mode, so that python output doesn't mix with
  // gtest output in buildbot log files. See http://crbug.com/147368.
  python_cmd->AppendArg("-u");

  return true;
}
