// Copyright 2013 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "ui/events/test/test_event_processor.h"

#include "ui/events/event_target.h"

namespace ui {
namespace test {

TestEventProcessor::TestEventProcessor() : num_times_processing_finished_(0) {}
TestEventProcessor::~TestEventProcessor() {}

void TestEventProcessor::SetRoot(scoped_ptr<EventTarget> root) {
  root_ = root.Pass();
}

void TestEventProcessor::ResetCounts() {
  num_times_processing_finished_ = 0;
}

bool TestEventProcessor::CanDispatchToTarget(EventTarget* target) {
  return true;
}

EventTarget* TestEventProcessor::GetRootTarget() {
  return root_.get();
}

EventDispatchDetails TestEventProcessor::OnEventFromSource(Event* event) {
  return EventProcessor::OnEventFromSource(event);
}

void TestEventProcessor::OnEventProcessingFinished(Event* event) {
  num_times_processing_finished_++;
}

}  // namespace test
}  // namespace ui
