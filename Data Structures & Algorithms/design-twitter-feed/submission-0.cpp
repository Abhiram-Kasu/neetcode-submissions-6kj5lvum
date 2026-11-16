
class Twitter {
    struct Tweet {
        int id;
        int time;
    };

    unordered_map<int, vector<Tweet>> tweets;
    unordered_map<int, unordered_set<int>> following;

    int timestamp = 0;

public:
    Twitter() = default;

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, timestamp++});
    }

    vector<int> getNewsFeed(int userId) {
        // {timestamp, userId, tweetIndex}
        using Entry = tuple<int, int, int>;
        priority_queue<Entry> pq;

        auto addLatest = [&](int uid) {
            auto it = tweets.find(uid);

            if (it == tweets.end() || it->second.empty())
                return;

            int index = (int)it->second.size() - 1;
            pq.emplace(it->second[index].time, uid, index);
        };
        addLatest(userId);
        for (int uid : following[userId]) {
            if (uid != userId)
                addLatest(uid);
        }

        vector<int> feed;

        while (!pq.empty() && feed.size() < 10) {
            auto [time, uid, index] = pq.top();
            pq.pop();

            feed.push_back(tweets[uid][index].id);

            // Add the next older tweet from this user.
            if (index > 0) {
                int next = index - 1;
                pq.emplace(tweets[uid][next].time,
                           uid, next);
            }
        }

        return feed;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId)
            following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};
