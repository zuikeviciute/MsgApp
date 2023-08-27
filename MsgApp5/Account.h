#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>
#include <msclr\marshal_cppstd.h>
#include "LinkedList1.h"

namespace MsgApp5
{
    using namespace std;

    /// <summary>
    /// Account holds all the information of user accounts
    /// </summary>
    class Account
    {
        private:
        int accountID;

        public:
        string username, password;
        

        Account() {};
        Account(int accID, string name, string pass) {
            accountID = accID;
            username = name;
            password = pass;
        };
    };

    /// <summary>
    /// Msg is the struct of messages,
    /// it holds all the information messages display
    /// </summary>
    public struct Msg {
    private:
        time_t timestamp;
    public:
        string msg, user, strTime;

        Msg() {};
        Msg(string msgContent, string acc) : msg(msgContent)
        {
            timestamp = time(nullptr);
            strTime = asctime(std::localtime(&timestamp));
            strTime = strTime.substr(11, 5);
            user = acc;
        }
    };

    /// <summary>
    /// Chat holds chat related information
    /// and the message Linked List that belongs to each chat
    /// used to retrieve messages from the message Linked List
    /// </summary>
    class Chat
    {
        public:
        LinkedList1<Msg> messages; //messages in this chat
        string joinCode, name;

        public:
        Chat() {};
        Chat(string chatName, string code) {
            name = chatName;
            joinCode = code;
        };

        void addMessage(Msg m) {
            messages.addLast(m);
        }

        void populate() {
            messages.addLast(Msg("Hello there", "John4"));
            messages.addLast(Msg("How are you doing?", "John4"));
            messages.addLast(Msg("I have an extra plane ticket for 4th of May, if any of you want to come?", "John4"));
            messages.addLast(Msg("Kate maybe?", "John4"));
        }

        string searchMessages(string searchInput) {
            return messages.search(searchInput);
        }

        string getMessages() {
            string str = "";
            int count = messages.getCount();

            for (int i = 0; i <= count; i++) {
                str += messages.itemAt(i).strTime + " [ " + messages.itemAt(i).user + " ] " + messages.itemAt(i).msg;
                if(i != count) str += "\r\n";
            }
            
            return str;
        }
    };
}
