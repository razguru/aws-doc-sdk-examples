/*
   Copyright Amazon.com, Inc. or its affiliates. All Rights Reserved.
   SPDX-License-Identifier: Apache-2.0
*/
/*
 * Test types are indicated by the test label ending.
 *
 * _1_ Requires credentials, permissions, and AWS resources.
 * _2_ Requires credentials and permissions.
 * _3_ Does not require credentials.
 *
 */

#include <gtest/gtest.h>
#include "ses_samples.h"
#include "ses_gtests.h"

namespace AwsDocTest {
    // NOLINTNEXTLINE(readability-named-parameter)
    TEST_F(SES_GTests, verify_email_identity_3_) {
        MockHTTP mockHttp;
        bool result = mockHttp.addResponseWithBody("mock_input/VerifyEmailIdentity.xml");
        ASSERT_TRUE(result) << preconditionError() << std::endl;

        result = AwsDoc::SES::verifyEmailIdentity("mock@email.com", *s_clientConfig);
        ASSERT_TRUE(result);
    }
} // namespace AwsDocTest
