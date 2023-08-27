#pragma once

#include <iostream>
#include <algorithm>
#include <iterator>

namespace MsgApp5 {
    using namespace std;

    //generic Node class for LinkedList
    template<class L>
    class Node
    {
    public:
        L value;
        Node<L>* next;

        Node(L v)
        {
            value = v;
            next = nullptr;
        }
    };

    /// <summary>
    /// Singly Linked List
    /// </summary>
    /// <typeparam name="L"></typeparam>
    template<class L>
    class LinkedList1
    {

    private:
        Node<L>* start;
    public:
        int count;
        LinkedList1()
        {
            count = 0;
            start = nullptr;
        }

        /// <summary>
        /// Checks if the list is empty
        /// </summary>
        /// <returns></returns>
        bool isEmpty()
        {
            return (start == nullptr);
        }

        /// <summary>
        /// Returns the count of the list
        /// </summary>
        /// <returns></returns>
        int getCount() {
            Node<L>* current = start;

            int count2 = 0;
            while (current->next != nullptr) {
                current = current->next;
                count2++;
            }

            return count2;
        }

        /// <summary>
        /// Adds the passed value to the end of the list
        /// </summary>
        /// <param name="value"></param>
        void addLast(L value)
        {
            Node<L>* n = new Node<L>(value);
            
            if (isEmpty())
            {
                //if the list is empty the value is just added to the start of the list
                start = n;
            }
            else
            {
                Node<L>* current = start;

                //finds the last value in the list 
                while (current->next != nullptr)
                    current = current->next;

                //sets the next value in the list to the new node
                current->next = n;
            }
            count++;
        }

        /// <summary>
        /// Finds item atspecified index
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        L itemAt(int index) {
            Node<L>* current = start;
            int temp = 0;

            if (index == 0 && start != nullptr) return start->value;

            //finds the value in the list 
            while (current->next != nullptr && temp < index) {
                current = current->next;
                temp++;
            }
            return current->value;
        }

        /// <summary>
        /// Linear Search algorithm
        /// </summary>
        /// <param name="searchInput"></param>
        /// <returns></returns>
        string search(string searchInput) {
            Node<Msg>* current = start;
            string str = "";
            while (current != nullptr) {
                if (current->value.strTime == searchInput || current->value.msg == searchInput || current->value.user == searchInput ||
                    current->value.msg.find(searchInput) != -1 || current->value.user.find(searchInput) != -1 || current->value.strTime.find(searchInput) != -1){
                    
                    str += current->value.strTime + " [ " + current->value.user + " ] " + current->value.msg + "\r\n";
                }

                current = current->next;
            }
            
            if (str == "") str = "no results found";

            return str;
        }

        /// <summary>
        /// Checks if account exists
        /// </summary>
        /// <param name="toSearch"></param>
        /// <param name="pass"></param>
        /// <returns></returns>
        int loginCheck(string toSearch, string pass) {
            Node<Account>* current = start;
            int temp = 0;

            //finds the last value in the list 
            while (current->next != nullptr && toSearch != current->value.username) {
                current = current->next;
                temp++;
            }

            if (toSearch == current->value.username && pass == current->value.password) {
                return temp;
            }

            return -1;
        }

        /// <summary>
        /// Checks if chat code exists 
        /// if it does returns -1 and shows error that a chat with that code already exists
        /// if no chat with the entered code exists returns 
        /// </summary>
        /// <param name="chatCode"></param>
        /// <returns></returns>
        int chatCheck(string chatCode) {
            Node<Chat>* current = start;
            int temp = 0;

            while (current != nullptr) {
                if (chatCode == current->value.joinCode) return -1;
                current = current->next;
            }

            return temp;
        }

        /// <summary>
        /// Checks if chat with the given code exists
        /// if it does the chat is joined
        /// </summary>
        /// <param name="code"></param>
        /// <returns></returns>
        int joinChatCheck(string code) {
            Node<Chat>* current = start;
            int temp = 0;

            //finds the last value in the list 
            while (current->next != nullptr && code != current->value.joinCode) {
                current = current->next;
                temp++;
            }
            if (code == current->value.joinCode) return temp;
            return -1;
        }


    };
}


