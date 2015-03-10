// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "extensions/browser/warning_service.h"

#include "content/public/test/test_browser_context.h"
#include "extensions/browser/extensions_test.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"

namespace extensions {

namespace {

class TestWarningService : public WarningService {
 public:
  explicit TestWarningService(content::BrowserContext* browser_context)
      : WarningService(browser_context) {
  }
  virtual ~TestWarningService() {}

  void AddWarning(const Warning& warning) {
    WarningSet warnings;
    warnings.insert(warning);
    AddWarnings(warnings);
  }
};

class MockObserver : public WarningService::Observer {
 public:
  virtual ~MockObserver() {}
  MOCK_METHOD0(ExtensionWarningsChanged, void());
};

typedef ExtensionsTest WarningServiceTest;

const char* ext1_id = "extension1";
const char* ext2_id = "extension2";
const Warning::WarningType warning_1 =
    Warning::kNetworkDelay;
const Warning::WarningType warning_2 =
    Warning::kNetworkConflict;

}  // namespace

// Check that inserting a warning triggers notifications, whereas inserting
// the same warning again is silent.
TEST_F(WarningServiceTest, SetWarning) {
  content::TestBrowserContext browser_context;
  TestWarningService warning_service(&browser_context);
  MockObserver observer;
  warning_service.AddObserver(&observer);

  // Insert warning for the first time.
  EXPECT_CALL(observer, ExtensionWarningsChanged());
  warning_service.AddWarning(
      Warning::CreateNetworkDelayWarning(ext1_id));
  testing::Mock::VerifyAndClearExpectations(&warning_service);

  // Second insertion of same warning does not trigger anything.
  warning_service.AddWarning(
      Warning::CreateNetworkDelayWarning(ext1_id));
  testing::Mock::VerifyAndClearExpectations(&warning_service);

  warning_service.RemoveObserver(&observer);
}

// Check that ClearWarnings deletes exactly the specified warnings and
// triggers notifications where appropriate.
TEST_F(WarningServiceTest, ClearWarnings) {
  content::TestBrowserContext browser_context;
  TestWarningService warning_service(&browser_context);
  MockObserver observer;
  warning_service.AddObserver(&observer);

  // Insert two unique warnings in one batch.
  EXPECT_CALL(observer, ExtensionWarningsChanged());
  WarningSet warning_set;
  warning_set.insert(Warning::CreateNetworkDelayWarning(ext1_id));
  warning_set.insert(Warning::CreateNetworkConflictWarning(ext2_id));
  warning_service.AddWarnings(warning_set);
  testing::Mock::VerifyAndClearExpectations(&warning_service);

  // Remove one warning and check that the badge remains.
  EXPECT_CALL(observer, ExtensionWarningsChanged());
  std::set<Warning::WarningType> to_clear;
  to_clear.insert(warning_2);
  warning_service.ClearWarnings(to_clear);
  testing::Mock::VerifyAndClearExpectations(&warning_service);

  // Check that the correct warnings appear in |warnings|.
  std::set<Warning::WarningType> existing_warnings =
      warning_service.GetWarningTypesAffectingExtension(ext1_id);
  EXPECT_EQ(1u, existing_warnings.size());
  existing_warnings =
      warning_service.GetWarningTypesAffectingExtension(ext2_id);
  EXPECT_EQ(0u, existing_warnings.size());

  // Remove the other one warning.
  EXPECT_CALL(observer, ExtensionWarningsChanged());
  to_clear.insert(warning_1);
  warning_service.ClearWarnings(to_clear);
  testing::Mock::VerifyAndClearExpectations(&warning_service);

  // Check that not warnings remain.
  existing_warnings =
      warning_service.GetWarningTypesAffectingExtension(ext1_id);
  EXPECT_EQ(0u, existing_warnings.size());
  existing_warnings =
      warning_service.GetWarningTypesAffectingExtension(ext2_id);
  EXPECT_EQ(0u, existing_warnings.size());

  warning_service.RemoveObserver(&observer);
}

}  // namespace extensions
