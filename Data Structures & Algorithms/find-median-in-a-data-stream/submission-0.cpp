class MedianFinder {
private:
    // left half uses max heap, while right half uses min heap
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // add to right first
        left.push(num);
        right.push(left.top());
        left.pop();

        // then check if right exceeds left, if so, push one element from right to left
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if (left.size() > right.size()) {
            return left.top();
        }

        return (left.top() + right.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */