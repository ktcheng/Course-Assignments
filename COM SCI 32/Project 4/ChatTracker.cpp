// ChatTracker.cpp

#include "ChatTracker.h"
#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <functional>

class ChatTrackerImpl
{
public:
    // Constructors and Destructors
    ChatTrackerImpl(int maxBuckets);

    // Mutators
    int terminate(std::string chat); // Terminates a chat
    int contribute(std::string user); // User contributes to chat
    int leave(std::string user, std::string chat); // User leaves a chat
    int leave(std::string user); // User leaves current chat
    void join(std::string user, std::string chat); // User joins a chat
private:
    // Private Helpers
    int hash(std::string key); // Hashes a string into an appropriate index

    // Private Structs
    struct Info
    {
        Info(std::string u, std::string c) : user(u), chat(c), count(0) {}
        std::string user;
        std::string chat;
        int count;
    };

    // Hash Tables (array of vectors)
    std::vector<std::vector<Info>> m_users; // User hash table
    std::vector<std::vector<Info>> m_chats; // Chat hash table
    std::vector<std::vector<Info>> m_usersWhoLeft; // Users who left hash table
    int m_buckets; // Keeps track of the maximum allowed number of buckets
};

// Private Helper: Hashes a string into a suitable hash table index
int ChatTrackerImpl::hash(std::string key)
{
    std::hash<std::string> str;
    return(str(key) % m_buckets);
}

// Constructor: Constructs a ChatTrackerImpl object
ChatTrackerImpl::ChatTrackerImpl(int maxBuckets)
    : m_users(maxBuckets), m_chats(maxBuckets), m_usersWhoLeft(maxBuckets), m_buckets(maxBuckets)
{
    // Since the default bucket number is 20,000, there is no point not to use
    // the full allotment of buckets. Hence, I have used a global constant to 
    // substitute for the bucket number.
}

// Mutator: User joins a particular chat
void ChatTrackerImpl::join(std::string user, std::string chat)
{
    // Retrieve the user and chat hash table indices
    int ui = hash(user);
    int ci = hash(chat);

    // Update the vector of user Infos, where appropriate
    std::vector<Info>::iterator it = m_users[ui].begin();
    while (it != m_users[ui].end())
    {
        // If the particular combination already exists, erase and push to back
        if (it->user == user && it->chat == chat)
        {
            Info info = *it;
            m_users[ui].erase(it);
            m_users[ui].push_back(info);
            return;
        }
        it++;
    }

    // If the vectors are empty, simply add a new Info struct
    m_users[ui].push_back(Info(user, chat));
    m_chats[ci].push_back(Info(user, chat));
}

// Mutator: A chat is terminated
int ChatTrackerImpl::terminate(std::string chat)
{
    int total = 0;
    int i = hash(chat); // Retrieve the chat hash table index

    // For matching Info in chat hash table, move Info from user to users who left hash table
    std::vector<Info>::iterator it = m_chats[i].begin();
    while (it != m_chats[i].end())
    {
        if (it->chat == chat)
        {
            // For matching Info, find user's corresponding Info and move to users who left
            int ui = hash(it->user);
            std::vector<Info>::iterator p = m_users[ui].end();
            while (p != m_users[ui].begin())
            {
                p--;
                if (p->chat == chat)
                {
                    total += p->count;
                    m_users[ui].erase(p);
                }
            }
        }

        it++;
    }

    // For matching Info in users who left hash table, add to our total
    it = m_usersWhoLeft[i].begin();
    while (it != m_usersWhoLeft[i].end())
    {
        if (it->chat == chat)
        {
            total += it->count;
            it = m_usersWhoLeft[i].erase(it);
        }
        else
        {
            it++;
        }
    }
    
    return(total);
}

// Mutator: User contributes to its current chat, if applicable
int ChatTrackerImpl::contribute(std::string user)
{
    int ui = hash(user); // Retrieve the user hash table index

    // For matching Info in user hash table, increment user's contributions
    std::vector<Info>::iterator it = m_users[ui].end(); 
    while (it != m_users[ui].begin())
    {
        it--;
        if (it->user == user)
        {
            it->count++;
            return(it->count);
        }
    }

    return(0);
}

// Mutator: User leaves a particularly specified chat, if applicable
int ChatTrackerImpl::leave(std::string user, std::string chat)
{
    // Retrieve the user and chat hash table indices
    int ui = hash(user);
    int ci = hash(chat);

    // For matching Info, move it from user hash table to users who left hash table
    std::vector<Info>::iterator it = m_users[ui].end();
    while (it != m_users[ui].begin())
    {
        it--;
        if (it->user == user && it->chat == chat)
        {
            int count = it->count;
            m_usersWhoLeft[ci].push_back(*it);
            m_users[ui].erase(it);
            return(count);
        }
    }

    return(-1);
}

// Mutator: User leaves its current chat, if applicable
int ChatTrackerImpl::leave(std::string user)
{
    int ui = hash(user); // Retrieve the user hash table index

    // For matching Info, move it from user hash table to users who left hash table
    std::vector<Info>::iterator it = m_users[ui].end();
    while (it != m_users[ui].begin())
    {
        it--;
        if (it->user == user)
        {
            int count = it->count;
            m_usersWhoLeft[hash(it->chat)].push_back(*it);
            m_users[ui].erase(it);
            return(count);
        }
    }

    return(-1);
}

//*********** ChatTracker functions **************

// These functions simply delegate to ChatTrackerImpl's functions.
// You probably don't want to change any of this code.

ChatTracker::ChatTracker(int maxBuckets)
{
    m_impl = new ChatTrackerImpl(maxBuckets);
}

ChatTracker::~ChatTracker()
{
    delete m_impl;
}

void ChatTracker::join(std::string user, std::string chat)
{
    m_impl->join(user, chat);
}

int ChatTracker::terminate(std::string chat)
{
    return m_impl->terminate(chat);
}

int ChatTracker::contribute(std::string user)
{
    return m_impl->contribute(user);
}

int ChatTracker::leave(std::string user, std::string chat)
{
    return m_impl->leave(user, chat);
}

int ChatTracker::leave(std::string user)
{
    return m_impl->leave(user);
}