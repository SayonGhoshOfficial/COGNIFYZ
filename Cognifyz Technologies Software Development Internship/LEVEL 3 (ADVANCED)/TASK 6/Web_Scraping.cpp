#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string fetch_html(const string& url) {
    stringstream response;
    if (url == "http://example.com") {
        string html = "<html><head><title>Example Domain</title></head><body><h1>Example Domain</h1></body></html>";
        response << html;
    } else {
        response << "Failed to fetch content from " << url;
    }
    return response.str();
}

string extract_title(const string& html) {
    size_t title_start = html.find("<title>");
    size_t title_end = html.find("</title>");
    if (title_start == string::npos || title_end == string::npos) {
        return "Title not found";
    }
    title_start += 7;
    return html.substr(title_start, title_end - title_start);
}

int main() {
    string url;
    cout << "Enter the URL to scrape: ";
    cin >> url;
    cout << "Fetching HTML content from " << url << "..." << endl;
    string html = fetch_html(url);
    if (!html.empty()) {
        string title = extract_title(html);
        cout << "Page Title: " << title << endl;
    } else {
        cout << "Failed to fetch HTML content!" << endl;
    }
    return 0;
}
