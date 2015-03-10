// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef EXTENSIONS_SHELL_BROWSER_SHELL_NACL_BROWSER_DELEGATE_H_
#define EXTENSIONS_SHELL_BROWSER_SHELL_NACL_BROWSER_DELEGATE_H_

#include "base/compiler_specific.h"
#include "base/macros.h"
#include "components/nacl/browser/nacl_browser_delegate.h"

namespace content {
class BrowserContext;
}

namespace extensions {
class InfoMap;

// A lightweight NaClBrowserDelegate for app_shell. Only supports a single
// BrowserContext.
class ShellNaClBrowserDelegate : public NaClBrowserDelegate {
 public:
  // Uses |context| to look up extensions via InfoMap on the IO thread.
  explicit ShellNaClBrowserDelegate(content::BrowserContext* context);
  virtual ~ShellNaClBrowserDelegate();

  // NaClBrowserDelegate overrides:
  virtual void ShowMissingArchInfobar(int render_process_id,
                                      int render_view_id) OVERRIDE;
  virtual bool DialogsAreSuppressed() OVERRIDE;
  virtual bool GetCacheDirectory(base::FilePath* cache_dir) OVERRIDE;
  virtual bool GetPluginDirectory(base::FilePath* plugin_dir) OVERRIDE;
  virtual bool GetPnaclDirectory(base::FilePath* pnacl_dir) OVERRIDE;
  virtual bool GetUserDirectory(base::FilePath* user_dir) OVERRIDE;
  virtual std::string GetVersionString() const OVERRIDE;
  virtual ppapi::host::HostFactory* CreatePpapiHostFactory(
      content::BrowserPpapiHost* ppapi_host) OVERRIDE;
  virtual bool MapUrlToLocalFilePath(const GURL& url,
                                     bool is_blocking,
                                     const base::FilePath& profile_directory,
                                     base::FilePath* file_path) OVERRIDE;
  virtual void SetDebugPatterns(std::string debug_patterns) OVERRIDE;
  virtual bool URLMatchesDebugPatterns(const GURL& manifest_url) OVERRIDE;
  virtual content::BrowserPpapiHost::OnKeepaliveCallback
      GetOnKeepaliveCallback() OVERRIDE;
  virtual bool IsNonSfiModeAllowed(const base::FilePath& profile_directory,
                                   const GURL& manifest_url) OVERRIDE;

 private:
  content::BrowserContext* browser_context_;  // Not owned.

  DISALLOW_COPY_AND_ASSIGN(ShellNaClBrowserDelegate);
};

}  // namespace extensions

#endif  // EXTENSIONS_SHELL_BROWSER_SHELL_NACL_BROWSER_DELEGATE_H_
