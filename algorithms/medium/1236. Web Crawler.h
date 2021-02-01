// 1236. Web Crawler
// https://leetcode.com/problems/web-crawler/

// Runtime: 84 ms, faster than 100.00% of C++ online submissions for Web Crawler.
// Memory Usage: 33 MB, less than 64.13% of C++ online submissions for Web Crawler.
    
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */

class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        auto i = startUrl.find('/');
        i = startUrl.find('/', i + 2);
        auto host = i == string::npos ? startUrl : startUrl.substr(0, i);
        const int L = host.length();
        // cout << host << endl;
        
        unordered_set<string> ans;
        ans.insert(startUrl);
        queue<string> q;
        q.push(startUrl);
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto urls = htmlParser.getUrls(q.front());
                q.pop();
                for (auto& url : urls) {
                    if (url.substr(0, L) != host || !ans.insert(url).second)
                        continue;
                    q.push(url);
                }
            }
        }
        return vector<string>(begin(ans), end(ans));
    }
};