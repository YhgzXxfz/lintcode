/**
 * Definition of Tweet:
 * class Tweet {
 * public:
 *     int id;
 *     int user_id;
 *     String text;
 *     static Tweet create(int user_id, string tweet_text) {
 *         // This will create a new tweet object,
 *         // and auto fill id
 *     }
 * }
 */
class MiniTwitter {
public:
    MiniTwitter() {
        // initialize your data structure here.
    }

    // @param user_id an integer
    // @param tweet a string
    // return a tweet
    Tweet postTweet(int user_id, string tweet_text) {
        //  Write your code here
        Tweet tw = Tweet::create(user_id, tweet_text);
        message_queue.insert(message_queue.begin(), make_pair(user_id, tw));
        return tw;
    }

    // @param user_id an integer
    // return a list of 10 new feeds recently
    // and sort by timeline
    vector<Tweet> getNewsFeed(int user_id) {
        // Write your code here
        vector<Tweet> result;
        
        unordered_set<int> toUsers;
        if (followmap.find(user_id) != followmap.end()) 
            toUsers = followmap[user_id];
            
        toUsers.insert(user_id);
        
        for (auto msg : message_queue) {
            if (toUsers.count(msg.first)) {
                result.push_back(msg.second);
                if (result.size() >= RecentTweet) break;
            }
        }
        
        return result;
    }
        
    // @param user_id an integer
    // return a list of 10 new posts recently
    // and sort by timeline
    vector<Tweet>  getTimeline(int user_id) {
        // Write your code here
        vector<Tweet> result;
        for (auto msg : message_queue) {
            if (msg.first == user_id) {
                result.push_back(msg.second);
                if (result.size() >= RecentTweet) break;
            }
        }
        
        return result;
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id follows to_user_id
    void follow(int from_user_id, int to_user_id) {
        // Write your code here
        if (followmap.find(from_user_id) == followmap.end()) {
            unordered_set<int> st;
            st.insert(to_user_id);
            followmap[from_user_id] = st;
        }
           
        else followmap[from_user_id].insert(to_user_id);
    }

    // @param from_user_id an integer
    // @param to_user_id an integer
    // from user_id unfollows to_user_id
    void unfollow(int from_user_id, int to_user_id) {
        // Write your code here
        if (followmap.find(from_user_id) == followmap.end()) return;
        
        followmap[from_user_id].erase(to_user_id);
    }
    
private:
    unordered_map<int, unordered_set<int>> followmap;
    vector<pair<int, Tweet>> message_queue;
    const int RecentTweet = 10;
};
