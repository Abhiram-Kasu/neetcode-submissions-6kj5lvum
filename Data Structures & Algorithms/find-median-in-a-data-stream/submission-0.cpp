class MedianFinder {
public:
    std::multiset<int> m_items;
    std::multiset<int>::iterator m_median = m_items.end();

    MedianFinder() = default;

    void addNum(int num) {
    if (m_items.empty()) {
        m_median = m_items.insert(num);
        return;
    }

    auto wasOdd = m_items.size() % 2 == 1;

    m_items.insert(num);

    if (wasOdd && num < *m_median) {
        --m_median;
    }
    else if (!wasOdd && num >= *m_median) {
        ++m_median;
    }
}

    double findMedian() {
        if ( m_items.size()%2 == 0) { 
            return (*m_median + *std::next(m_median)) / 2.0;
        }else { 
            return *m_median;
        }
    }
};