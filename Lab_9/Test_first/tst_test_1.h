#ifndef TST_TEST_1_H
#define TST_TEST_1_H
#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IKeypad.h>
#include <ILatch.h>
#include <lockcontroller.h>

using namespace testing;

struct Test_IKeypad: IKeypad{

    MOCK_METHOD(PasswordResponse, requestPassword, (), (override));
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(void, wait, (), (override));

};


struct Test_ILatch: ILatch{
    MOCK_METHOD(DoorStatus, close, (), (override));
    MOCK_METHOD(DoorStatus, getDoorStatus, (), (override));
    MOCK_METHOD(DoorStatus, open, (), (override));
    MOCK_METHOD(bool, isActive, (), (override));
};


struct All_Test: Test{

    void SetUp(){
        lock_controller = new LockController(&ikeypad, &ilatch);
    }
    void TearDown(){

    }
    Test_IKeypad ikeypad;
    Test_ILatch ilatch;
    LockController* lock_controller;
};
//Test_1

TEST_F(All_Test,ikeypad){

    EXPECT_CALL(ikeypad, wait())
            .Times(AtLeast(1));
    lock_controller->wait();

}
//Test_2
TEST_F(All_Test, ilathc){
    EXPECT_CALL(ilatch, getDoorStatus)
            .Times(AtLeast(1))
            .WillOnce(Return(DoorStatus::CLOSE));
    EXPECT_FALSE(lock_controller->isDoorOpen());

}
//Test_3
TEST_F(All_Test, ilatch){
    EXPECT_CALL(ilatch, getDoorStatus)
            .Times(AtLeast(1))
            .WillOnce(Return(DoorStatus::OPEN));
    EXPECT_TRUE(lock_controller->isDoorOpen());

}
//Test_4
TEST_F(All_Test, loch_controller){
    EXPECT_CALL(ilatch, open)
            .Times(AtLeast(1))
            .WillOnce(Return(DoorStatus::OPEN));
    EXPECT_EQ(lock_controller->unlockDoor(), DoorStatus::OPEN);

}
//Test_5
TEST_F(All_Test, lock_controller){
    EXPECT_CALL(ilatch, close)
            .Times(AtLeast(1))
            .WillOnce(Return(DoorStatus::CLOSE));
    EXPECT_EQ(lock_controller->lockDoor(), DoorStatus::CLOSE);

}
//Test_6
TEST_F(All_Test, ikeyp){
    EXPECT_CALL(ikeypad, isActive)
            .Times(AtLeast(1))
            .WillOnce(Return(1));
    EXPECT_CALL(ilatch, isActive)
            .Times(AtLeast(1))
            .WillOnce(Return(1));
    EXPECT_EQ(lock_controller->hardWareCheck(), HardWareStatus::OK);

}
//Test_7
TEST_F(All_Test, errorhardWareTest){
    delete lock_controller;
    lock_controller = new LockController(NULL, &ilatch);
    EXPECT_CALL(ikeypad, isActive)
            .Times(AtLeast(0))
            .WillOnce(Return(1));
    EXPECT_CALL(ilatch, isActive)
            .Times(AtLeast(0))
            .WillOnce(Return(1));
    EXPECT_EQ(lock_controller->hardWareCheck(), HardWareStatus::ERROR);

}
//Test_8
TEST_F(All_Test, LatchTest){
    EXPECT_CALL(ikeypad, isActive)
            .Times(AtLeast(0))
            .WillOnce(Return(1));
    EXPECT_CALL(ilatch, isActive)
            .Times(AtLeast(0))
            .WillOnce(Return(0));
    EXPECT_EQ(lock_controller->hardWareCheck(), HardWareStatus::ERROR);

}
//Test_9
TEST_F(All_Test, PasswordTest){
    PasswordResponse pass;
    pass.password = "0000";
    pass.status = PasswordResponse::Status::OK;
    EXPECT_CALL(ikeypad, requestPassword)
            .Times(AtLeast(1))
            .WillOnce(Return(pass));
    EXPECT_TRUE(lock_controller->isCorrectPassword());
}
//Test_10
TEST_F(All_Test, WrongPasswordTest){
    PasswordResponse pass;
    pass.password = "1234";
    pass.status = PasswordResponse::Status::OK;
    EXPECT_CALL(ikeypad, requestPassword)
            .Times(AtLeast(1))
            .WillOnce(Return(pass));
    EXPECT_FALSE(lock_controller->isCorrectPassword());
}
//Test_11
TEST_F(All_Test, ChangePasswordTest){
    PasswordResponse pass_old, pass_new, user_input;
    pass_old.password = "0000";
    pass_old.status = PasswordResponse::Status::OK;
    user_input.password = "1111";
    user_input.status = PasswordResponse::Status::OK;
    pass_new.password = "1111";
    pass_new.status = PasswordResponse::Status::OK;
    EXPECT_CALL(ikeypad, requestPassword)

            .WillOnce(Return(pass_old))
            .WillOnce(Return(user_input))
            .WillOnce(Return(pass_new));
    lock_controller->resetPassword();
    EXPECT_TRUE(lock_controller->isCorrectPassword());
}
//Test_12
TEST_F(All_Test, ChangePasswordWith){
    PasswordResponse parol_alt, parol_neu, user_in, parol_neu_2, user_in_2;
   parol_alt.password = "0000";
   parol_alt.status = PasswordResponse::Status::OK;
    user_in.password = "9876";
    user_in.status = PasswordResponse::Status::OK;
    parol_neu.password = "9876";
     parol_neu.status = PasswordResponse::Status::OK;
    user_in_2.password = "1111";
    user_in_2.status = PasswordResponse::Status::OK;
    parol_neu_2.password = "1111";
    parol_neu_2.status = PasswordResponse::Status::OK;
    EXPECT_CALL(ikeypad, requestPassword)

            .WillOnce(Return(parol_alt))
            .WillOnce(Return(parol_neu))
            .WillOnce(Return(user_in))
            .WillOnce(Return(parol_neu_2))
            .WillOnce(Return(user_in_2));

    lock_controller->resetPassword();
    lock_controller->resetPassword();
    EXPECT_TRUE(lock_controller->isCorrectPassword());
}


#endif
