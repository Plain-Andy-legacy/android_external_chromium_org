// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "remoting/protocol/jingle_messages.h"

#include "base/logging.h"
#include "testing/gmock/include/gmock/gmock.h"
#include "testing/gtest/include/gtest/gtest.h"
#include "third_party/libjingle/source/talk/xmpp/constants.h"
#include "third_party/webrtc/libjingle/xmllite/xmlelement.h"

using buzz::QName;
using buzz::XmlAttr;
using buzz::XmlElement;

namespace remoting {
namespace protocol {

namespace {

const char kXmlNsNs[] = "http://www.w3.org/2000/xmlns/";
const char kXmlNs[] = "xmlns";

// Compares two XML blobs and returns true if they are
// equivalent. Otherwise |error| is set to error message that
// specifies the first test.
bool VerifyXml(const XmlElement* exp,
               const XmlElement* val,
               std::string* error) {
  if (exp->Name() != val->Name()) {
    *error = "<" + exp->Name().Merged() + ">" + " is expected, but " +
        "<" + val->Name().Merged() + ">"  + " found";
    return false;
  }
  if (exp->BodyText() != val->BodyText()) {
    *error = "<" + exp->Name().LocalPart() + ">" + exp->BodyText() +
        "</" + exp->Name().LocalPart() + ">" " is expected, but found " +
        "<" + exp->Name().LocalPart() + ">" + val->BodyText() +
        "</" + exp->Name().LocalPart() + ">";
    return false;
  }

  for (const XmlAttr* exp_attr = exp->FirstAttr(); exp_attr != NULL;
       exp_attr = exp_attr->NextAttr()) {
    if (exp_attr->Name().Namespace() == kXmlNsNs ||
        exp_attr->Name() == QName(kXmlNs)) {
      continue; // Skip NS attributes.
    }
    if (val->Attr(exp_attr->Name()) != exp_attr->Value()) {
      *error = "In <" + exp->Name().LocalPart() + "> attribute " +
          exp_attr->Name().LocalPart() + " is expected to be set to " +
          exp_attr->Value();
      return false;
    }
  }

  for (const XmlAttr* val_attr = val->FirstAttr(); val_attr;
       val_attr = val_attr->NextAttr()) {
    if (val_attr->Name().Namespace() == kXmlNsNs ||
        val_attr->Name() == QName(kXmlNs)) {
      continue; // Skip NS attributes.
    }
    if (exp->Attr(val_attr->Name()) != val_attr->Value()) {
      *error = "In <" + exp->Name().LocalPart() + "> unexpected attribute " +
          val_attr->Name().LocalPart();
      return false;
    }
  }

  const XmlElement* exp_child = exp->FirstElement();
  const XmlElement* val_child = val->FirstElement();
  while (exp_child && val_child) {
    if (!VerifyXml(exp_child, val_child, error))
      return false;
    exp_child = exp_child->NextElement();
    val_child = val_child->NextElement();
  }
  if (exp_child) {
    *error = "<" + exp_child->Name().Merged() + "> is expected, but not found";
    return false;
  }

  if (val_child) {
    *error = "Unexpected <" + val_child->Name().Merged() + "> found";
    return false;
  }

  return true;
}

}  // namespace

// Each of the tests below try to parse a message, format it again,
// and then verify that the formatted message is the same as the
// original stanza. The sample messages were generated by libjingle.

TEST(JingleMessageTest, SessionInitiate) {
  const char* kTestSessionInitiateMessage =
      "<iq to='user@gmail.com/chromoting016DBB07' type='set' "
        "from='user@gmail.com/chromiumsy5C6A652D' "
        "xmlns='jabber:client'>"
        "<jingle xmlns='urn:xmpp:jingle:1' "
          "action='session-initiate' sid='2227053353' "
          "initiator='user@gmail.com/chromiumsy5C6A652D'>"
          "<content name='chromoting' creator='initiator'>"
            "<description xmlns='google:remoting'>"
              "<control transport='stream' version='2'/>"
              "<event transport='stream' version='2'/>"
              "<video transport='stream' version='2' codec='vp8'/>"
              "<audio transport='stream' version='2' codec='verbatim'/>"
              "<initial-resolution width='640' height='480'/>"
              "<authentication><auth-token>"
                "j7whCMii0Z0AAPwj7whCM/j7whCMii0Z0AAPw="
              "</auth-token></authentication>"
          "</description>"
          "<transport xmlns='http://www.google.com/transport/p2p'/>"
          "</content>"
        "</jingle>"
      "</iq>";
  scoped_ptr<XmlElement> source_message(
      XmlElement::ForStr(kTestSessionInitiateMessage));
  ASSERT_TRUE(source_message.get());

  EXPECT_TRUE(JingleMessage::IsJingleMessage(source_message.get()));

  JingleMessage message;
  std::string error;
  EXPECT_TRUE(message.ParseXml(source_message.get(), &error)) << error;

  EXPECT_EQ(message.action, JingleMessage::SESSION_INITIATE);

  scoped_ptr<XmlElement> formatted_message(message.ToXml());
  ASSERT_TRUE(formatted_message.get());
  EXPECT_TRUE(VerifyXml(formatted_message.get(), source_message.get(), &error))
      << error;
}

TEST(JingleMessageTest, SessionAccept) {
  const char* kTestSessionAcceptMessage =
      "<cli:iq from='user@gmail.com/chromoting016DBB07' "
        "to='user@gmail.com/chromiumsy5C6A652D' type='set' "
        "xmlns:cli='jabber:client'>"
        "<jingle action='session-accept' sid='2227053353' "
          "xmlns='urn:xmpp:jingle:1'>i"
          "<content creator='initiator' name='chromoting'>"
            "<description xmlns='google:remoting'>"
              "<control transport='stream' version='2'/>"
              "<event transport='stream' version='2'/>"
              "<video codec='vp8' transport='stream' version='2'/>"
              "<audio transport='stream' version='2' codec='verbatim'/>"
              "<initial-resolution height='480' width='640'/>"
              "<authentication><certificate>"
                "MIICpjCCAY6gW0Cert0TANBgkqhkiG9w0BAQUFA="
              "</certificate></authentication>"
            "</description>"
            "<transport xmlns='http://www.google.com/transport/p2p'/>"
          "</content>"
        "</jingle>"
      "</cli:iq>";

  scoped_ptr<XmlElement> source_message(
      XmlElement::ForStr(kTestSessionAcceptMessage));
  ASSERT_TRUE(source_message.get());

  EXPECT_TRUE(JingleMessage::IsJingleMessage(source_message.get()));

  JingleMessage message;
  std::string error;
  EXPECT_TRUE(message.ParseXml(source_message.get(), &error)) << error;

  EXPECT_EQ(message.action, JingleMessage::SESSION_ACCEPT);

  scoped_ptr<XmlElement> formatted_message(message.ToXml());
  ASSERT_TRUE(formatted_message.get());
  EXPECT_TRUE(VerifyXml(source_message.get(), formatted_message.get(), &error))
      << error;
}

TEST(JingleMessageTest, TransportInfo) {
  const char* kTestTransportInfoMessage =
      "<cli:iq to='user@gmail.com/chromoting016DBB07' type='set' "
      "xmlns:cli='jabber:client'><jingle xmlns='urn:xmpp:jingle:1' "
      "action='transport-info' sid='2227053353'><content name='chromoting' "
      "creator='initiator'><transport "
      "xmlns='http://www.google.com/transport/p2p'><candidate name='event' "
      "address='172.23.164.186' port='57040' preference='1' "
      "username='tPUyEAmQrEw3y7hi' protocol='udp' generation='0' "
      "password='2iRdhLfawKZC5ydJ' type='local'/><candidate name='video' "
      "address='172.23.164.186' port='42171' preference='1' "
      "username='EPK3CXo5sTLJSez0' protocol='udp' generation='0' "
      "password='eM0VUfUkZ+1Pyi0M' type='local'/></transport></content>"
      "</jingle></cli:iq>";

  scoped_ptr<XmlElement> source_message(
      XmlElement::ForStr(kTestTransportInfoMessage));
  ASSERT_TRUE(source_message.get());

  EXPECT_TRUE(JingleMessage::IsJingleMessage(source_message.get()));

  JingleMessage message;
  std::string error;
  EXPECT_TRUE(message.ParseXml(source_message.get(), &error)) << error;

  EXPECT_EQ(message.action, JingleMessage::TRANSPORT_INFO);
  EXPECT_EQ(message.candidates.size(), 2U);

  scoped_ptr<XmlElement> formatted_message(message.ToXml());
  ASSERT_TRUE(formatted_message.get());
  EXPECT_TRUE(VerifyXml(source_message.get(), formatted_message.get(), &error))
      << error;
}

TEST(JingleMessageTest, SessionTerminate) {
  const char* kTestSessionTerminateMessage =
      "<cli:iq from='user@gmail.com/chromoting016DBB07' "
      "to='user@gmail.com/chromiumsy5C6A652D' type='set' "
      "xmlns:cli='jabber:client'><jingle action='session-terminate' "
      "sid='2227053353' xmlns='urn:xmpp:jingle:1'><reason><success/>"
      "</reason></jingle></cli:iq>";

  scoped_ptr<XmlElement> source_message(
      XmlElement::ForStr(kTestSessionTerminateMessage));
  ASSERT_TRUE(source_message.get());

  EXPECT_TRUE(JingleMessage::IsJingleMessage(source_message.get()));

  JingleMessage message;
  std::string error;
  EXPECT_TRUE(message.ParseXml(source_message.get(), &error)) << error;

  EXPECT_EQ(message.action, JingleMessage::SESSION_TERMINATE);

  scoped_ptr<XmlElement> formatted_message(message.ToXml());
  ASSERT_TRUE(formatted_message.get());
  EXPECT_TRUE(VerifyXml(source_message.get(), formatted_message.get(), &error))
      << error;
}

TEST(JingleMessageTest, SessionInfo) {
  const char* kTestSessionTerminateMessage =
      "<cli:iq from='user@gmail.com/chromoting016DBB07' "
      "to='user@gmail.com/chromiumsy5C6A652D' type='set' "
      "xmlns:cli='jabber:client'><jingle action='session-info' "
      "sid='2227053353' xmlns='urn:xmpp:jingle:1'><test-info>TestMessage"
      "</test-info></jingle></cli:iq>";

  scoped_ptr<XmlElement> source_message(
      XmlElement::ForStr(kTestSessionTerminateMessage));
  ASSERT_TRUE(source_message.get());

  EXPECT_TRUE(JingleMessage::IsJingleMessage(source_message.get()));

  JingleMessage message;
  std::string error;
  EXPECT_TRUE(message.ParseXml(source_message.get(), &error)) << error;

  EXPECT_EQ(message.action, JingleMessage::SESSION_INFO);
  ASSERT_TRUE(message.info.get() != NULL);
  EXPECT_TRUE(message.info->Name() ==
              buzz::QName("urn:xmpp:jingle:1", "test-info"));

  scoped_ptr<XmlElement> formatted_message(message.ToXml());
  ASSERT_TRUE(formatted_message.get());
  EXPECT_TRUE(VerifyXml(source_message.get(), formatted_message.get(), &error))
      << error;
}

TEST(JingleMessageReplyTest, ToXml) {
  const char* kTestIncomingMessage =
      "<cli:iq from='user@gmail.com/chromoting016DBB07' id='4' "
      "to='user@gmail.com/chromiumsy5C6A652D' type='set' "
      "xmlns:cli='jabber:client'><jingle action='session-terminate' "
      "sid='2227053353' xmlns='urn:xmpp:jingle:1'><reason><success/>"
      "</reason></jingle></cli:iq>";
  scoped_ptr<XmlElement> incoming_message(
      XmlElement::ForStr(kTestIncomingMessage));
  ASSERT_TRUE(incoming_message.get());

  struct TestCase {
    const JingleMessageReply::ErrorType error;
    std::string error_text;
    std::string expected_text;
  } tests[] = {
    { JingleMessageReply::BAD_REQUEST, "", "<iq xmlns='jabber:client' "
      "to='user@gmail.com/chromoting016DBB07' id='4' type='error'><jingle "
      "action='session-terminate' sid='2227053353' xmlns='urn:xmpp:jingle:1'>"
      "<reason><success/></reason></jingle><error type='modify'><bad-request/>"
      "</error></iq>" },
    { JingleMessageReply::BAD_REQUEST, "ErrorText", "<iq xmlns='jabber:client' "
      "to='user@gmail.com/chromoting016DBB07' id='4' type='error'><jingle "
      "action='session-terminate' sid='2227053353' xmlns='urn:xmpp:jingle:1'>"
      "<reason><success/></reason></jingle><error type='modify'><bad-request/>"
      "<text xml:lang='en'>ErrorText</text></error></iq>" },
    { JingleMessageReply::NOT_IMPLEMENTED, "", "<iq xmlns='jabber:client' "
      "to='user@gmail.com/chromoting016DBB07' id='4' type='error'><jingle "
      "action='session-terminate' sid='2227053353' xmlns='urn:xmpp:jingle:1'>"
      "<reason><success/></reason></jingle><error type='cancel'>"
      "<feature-bad-request/></error></iq>" },
    { JingleMessageReply::INVALID_SID, "",  "<iq xmlns='jabber:client' "
      "to='user@gmail.com/chromoting016DBB07' id='4' type='error'><jingle "
      "action='session-terminate' sid='2227053353' xmlns='urn:xmpp:jingle:1'>"
      "<reason><success/></reason></jingle><error type='modify'>"
      "<item-not-found/><text xml:lang='en'>Invalid SID</text></error></iq>" },
    { JingleMessageReply::INVALID_SID, "ErrorText", "<iq xmlns='jabber:client' "
      "to='user@gmail.com/chromoting016DBB07' id='4' type='error'><jingle "
      "action='session-terminate' sid='2227053353' xmlns='urn:xmpp:jingle:1'>"
      "<reason><success/></reason></jingle><error type='modify'>"
      "<item-not-found/><text xml:lang='en'>ErrorText</text></error></iq>" },
    { JingleMessageReply::UNEXPECTED_REQUEST, "", "<iq xmlns='jabber:client' "
      "to='user@gmail.com/chromoting016DBB07' id='4' type='error'><jingle "
      "action='session-terminate' sid='2227053353' xmlns='urn:xmpp:jingle:1'>"
      "<reason><success/></reason></jingle><error type='modify'>"
      "<unexpected-request/></error></iq>" },
  };

  for (size_t i = 0; i < ARRAYSIZE_UNSAFE(tests); ++i) {
    JingleMessageReply reply_msg;
    if (tests[i].error_text.empty()) {
      reply_msg = JingleMessageReply(tests[i].error);
    } else {
      reply_msg = JingleMessageReply(tests[i].error, tests[i].error_text);
    }
    scoped_ptr<XmlElement> reply(reply_msg.ToXml(incoming_message.get()));

    scoped_ptr<XmlElement> expected(XmlElement::ForStr(tests[i].expected_text));
    ASSERT_TRUE(expected.get());

    std::string error;
    EXPECT_TRUE(VerifyXml(expected.get(), reply.get(), &error)) << error;
  }
}

TEST(JingleMessageTest, ErrorMessage) {
  const char* kTestSessionInitiateErrorMessage =
      "<iq to='user@gmail.com/chromoting016DBB07' type='error' "
        "from='user@gmail.com/chromiumsy5C6A652D' "
        "xmlns='jabber:client'>"
        "<jingle xmlns='urn:xmpp:jingle:1' "
        "action='session-initiate' sid='2227053353' "
        "initiator='user@gmail.com/chromiumsy5C6A652D'>"
          "<content name='chromoting' creator='initiator'>"
            "<description xmlns='google:remoting'>"
              "<control transport='stream' version='2'/>"
              "<event transport='stream' version='2'/>"
              "<video transport='stream' version='2' codec='vp8'/>"
              "<audio transport='stream' version='2' codec='verbatim'/>"
              "<initial-resolution width='800' height='600'/>"
              "<authentication><auth-token>"
                "j7whCMii0Z0AAPwj7whCM/j7whCMii0Z0AAPw="
              "</auth-token></authentication>"
            "</description>"
            "<transport xmlns='http://www.google.com/transport/p2p'/>"
          "</content>"
        "</jingle>"
        "<error code='501' type='cancel'>"
          "<feature-not-implemented "
            "xmlns='urn:ietf:params:xml:ns:xmpp-stanzas'/>"
        "</error>"
      "</iq>";
  scoped_ptr<XmlElement> source_message(
      XmlElement::ForStr(kTestSessionInitiateErrorMessage));
  ASSERT_TRUE(source_message.get());

  EXPECT_FALSE(JingleMessage::IsJingleMessage(source_message.get()));

  JingleMessage message;
  std::string error;
  EXPECT_FALSE(message.ParseXml(source_message.get(), &error));
  EXPECT_FALSE(error.empty());
}

}  // namespace protocol
}  // namespace remoting
