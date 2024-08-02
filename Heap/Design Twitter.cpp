// Leetcode - 355

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
        auto cmp = [](const tuple<int, int, int, int>& a,
                      const tuple<int, int, int, int>& b) {
            return get<0>(a) < get<0>(b); // max-heap based on time
        };
        priority_queue<tuple<int, int, int, int>,
                       vector<tuple<int, int, int, int>>, decltype(cmp)>
            pq(cmp);

        auto addTweets = [&](int id) {
            if (tweets.find(id) != tweets.end()) {
                const auto& tweetList = tweets[id];
                if (!tweetList.empty()) {
                    pq.push({tweetList.back().first, tweetList.back().second,
                             id, tweetList.size() - 1});
                }
            }
        };

        addTweets(userId);

        for (int followerId : follower[userId]) {
            addTweets(followerId);
        }

        while (!pq.empty() && res.size() < 10) {
            auto [tweetTime, tweetId, userId, tweetIndex] = pq.top();
            pq.pop();
            res.push_back(tweetId);
            if (tweetIndex > 0) {
                const auto& tweetList = tweets[userId];
                pq.push({tweetList[tweetIndex - 1].first,
                         tweetList[tweetIndex - 1].second, userId,
                         tweetIndex - 1});
            }
        }
        return res;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) { // a user should not follow themselves
            follower[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) { // a user should not unfollow themselves
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
