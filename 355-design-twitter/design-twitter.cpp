
class Twitter {
public:
    static int timeStamp;
    
    struct Tweet {
        int id;
        int time;
        Tweet* next;
        Tweet(int id) : id(id), time(timeStamp++), next(nullptr) {}
    };
    
    struct User {
        int id;
        unordered_set<int> followed;
        Tweet* tweetHead;
        
        User(int id) : id(id), tweetHead(nullptr) {
            follow(id); // User follows itself
        }
        
        void follow(int userId) {
            followed.insert(userId);
        }
        
        void unfollow(int userId) {
            if (userId != id) {
                followed.erase(userId);
            }
        }
        
        void post(int tweetId) {
            Tweet* newTweet = new Tweet(tweetId);
            newTweet->next = tweetHead;
            tweetHead = newTweet;
        }
    };
    
    unordered_map<int, User*> userMap;
    
public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        if (userMap.find(userId) == userMap.end()) {
            userMap[userId] = new User(userId);
        }
        userMap[userId]->post(tweetId);
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> newsFeed;
        if (userMap.find(userId) == userMap.end()) return newsFeed;
        
        unordered_set<int> followedUsers = userMap[userId]->followed;
        auto cmp = [](Tweet* a, Tweet* b) { return a->time < b->time; };
        priority_queue<Tweet*, vector<Tweet*>, decltype(cmp)> tweetHeap(cmp);
        
        for (int user : followedUsers) {
            if (userMap[user]->tweetHead) {
                tweetHeap.push(userMap[user]->tweetHead);
            }
        }
        
        int count = 0;
        while (!tweetHeap.empty() && count < 10) {
            Tweet* tweet = tweetHeap.top();
            tweetHeap.pop();
            newsFeed.push_back(tweet->id);
            count++;
            if (tweet->next) {
                tweetHeap.push(tweet->next);
            }
        }
        
        return newsFeed;
    }
    
    void follow(int followerId, int followeeId) {
        if (userMap.find(followerId) == userMap.end()) {
            userMap[followerId] = new User(followerId);
        }
        if (userMap.find(followeeId) == userMap.end()) {
            userMap[followeeId] = new User(followeeId);
        }
        userMap[followerId]->follow(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if (userMap.find(followerId) != userMap.end() && followerId != followeeId) {
            userMap[followerId]->unfollow(followeeId);
        }
    }
};
int Twitter::timeStamp = 0;