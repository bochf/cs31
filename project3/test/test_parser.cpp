#include <gtest/gtest.h>

#include <parser.h>

TEST(TestParser, TestValid) {
  EXPECT_TRUE(isValidVendingMachineString("D$PA1"));
  EXPECT_TRUE(isValidVendingMachineString("DqDqDqDqDpD$PA0PA9"));
  EXPECT_TRUE(isValidVendingMachineString("MqMqMqMqDpD$PB3"));
  EXPECT_TRUE(isValidVendingMachineString("D$MqMqMqMqDpD$PC4"));
  EXPECT_TRUE(isValidVendingMachineString("M$DpR"));
  EXPECT_TRUE(isValidVendingMachineString("MqDqMqDqPA3"));
  EXPECT_TRUE(isValidVendingMachineString("M$D$PA1PA2"));
  EXPECT_TRUE(isValidVendingMachineString("D$M$PB3"));
  EXPECT_TRUE(isValidVendingMachineString("D$PA1R"));
  EXPECT_TRUE(isValidVendingMachineString("D$RR"));
}

TEST(TestParser, TestInvalid) {
  EXPECT_FALSE(isValidVendingMachineString("D$"));
  EXPECT_FALSE(isValidVendingMachineString("xyz"));
  EXPECT_FALSE(isValidVendingMachineString("M$"));
  EXPECT_FALSE(isValidVendingMachineString("M$PA1 zzz"));
  EXPECT_FALSE(isValidVendingMachineString("M$RPA3"));
  EXPECT_FALSE(isValidVendingMachineString("MpDdPA1"));
}

TEST(TestParser, TestRefund) {
  EXPECT_DOUBLE_EQ(2.25, changeReturned("MqD$M$R"));
  EXPECT_DOUBLE_EQ(0.25, changeReturned("DnDdRD$D$DqPB7"));
  EXPECT_DOUBLE_EQ(0.25, changeReturned("MqD$M$PB0R"));
  EXPECT_DOUBLE_EQ(0.25, changeReturned("MqD$M$PB0"));
  EXPECT_DOUBLE_EQ(2.00, changeReturned("D$RM$D$R"));
  EXPECT_DOUBLE_EQ(0.00, changeReturned("D$PA1R"));
  EXPECT_DOUBLE_EQ(0.00, changeReturned("D$RR"));
}
