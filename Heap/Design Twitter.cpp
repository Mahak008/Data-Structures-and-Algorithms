// Leetcode - 355

class compare {
public:
    bool operator()(const vector<int>& a, const vector<int>& b) {
        // Compare by time (a[0] > b[0]) for max-heap (latest tweets first)
        return a[0] < b[0];
    }
};

class Twitter {
public:
    unordered_map<int, unordered_set<int>> follower;
    unordered_map<int, vector<pair<int, int>>> tweets;
    int time = 0;

    Twitter() {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({++time, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        priority_queue<vector<int>, vector<vector<int>>, compare> pq;

        // Add user's own tweets
        if (tweets.find(userId) != tweets.end()) {
            const auto& tweetList = tweets[userId];
            if (!tweetList.empty()) {
                // Start from the most recent tweet
                pq.push({tweetList.back().first, tweetList.back().second,
                         userId, static_cast<int>(tweetList.size()) - 1});
            }
        }

        // Add followers' tweets
        for (int followerId : follower[userId]) {
            if (tweets.find(followerId) != tweets.end()) {
                const auto& tweetList = tweets[followerId];
                if (!tweetList.empty()) {
                    // Start from the most recent tweet
                    pq.push({tweetList.back().first, tweetList.back().second,
                             followerId,
                             static_cast<int>(tweetList.size()) - 1});
                }
            }
        }

        // Collect up to 10 most recent tweets
        while (!pq.empty() && res.size() < 10) {
            auto tweet = pq.top();
            pq.pop();
            res.push_back(tweet[1]);

            int userId = tweet[2];
            int index = tweet[3] - 1;

            if (index >= 0) {
                const auto& tweetList = tweets[userId];
                pq.push({tweetList[index].first, tweetList[index].second,
                         userId, index});
            }
        }

        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) { // A user should not follow themselves
            follower[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) { // A user should not unfollow themselves
            follower[followerId].erase(followeeId);
        }
    }
};


// Input:
// ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed", "unfollow", "getNewsFeed"]
// [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
// Output:
// [null, null, [5], null, null, [6, 5], null, [5]]

// Explanation:
// Twitter twitter = new Twitter();
// twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5]. return [5]
// twitter.follow(1, 2);    // User 1 follows user 2.
// twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2 tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
// twitter.unfollow(1, 2);  // User 1 unfollows user 2.
// twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1 tweet id -> [5], since user 1 is no longer following user 2.
