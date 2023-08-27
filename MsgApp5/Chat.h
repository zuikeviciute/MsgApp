#pragma once
#include <iostream>
#include <algorithm>
#include <iterator>
#include "Account.h"

namespace MsgApp5
{
    using namespace std;
    //chat is a class responsible for accessibility of message linked lists it holds associated user information
    class Chat1
    {
        private:
        int chatID, chatCode; //id and join code to invite other people
        LinkedList1<Account> accounts; //accounts that have access to this chat
        LinkedList1<Msg> messages; //messages in this chat

        public:
        Chat1() {
            chatID = 0;
            chatCode = 0;
        };

        Chat1(Account* acc) {
            chatID = 0;
            chatCode = 0;
            //user1 = acc;
        };

        void createMsg(Account a) {

            //messages.addLast(Msg("yo", messages.count, a));
            //messages.displayMessages(); //messages displayed lol style

        };
    };
}
