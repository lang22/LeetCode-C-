//
// Created by lang22 on 2021/2/3.
//

#ifndef LEETCODE_MEDIANFINDER_H
#define LEETCODE_MEDIANFINDER_H
#include <iostream>
#include <queue>
#include <vector>
using namespace  std;
class MedianFinder {
    // 将数据流分为low, high两部分
    // 分别用一个大顶堆和一个小顶堆维护low、high两部分
    // 添加元素时，保持两个堆的平衡，保证low部分的大小-high部分的大小>=1
    // 大顶堆的顶是low中最大元素，小顶堆的顶是high中最小元素
    // 中位数可通过两个堆的顶取得
private:
    priority_queue<int> low; // 大顶堆，用来存low部分
    priority_queue<int, vector<int>, greater<int>> high; // 小顶堆，用来存high部分
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }

    void addNum(int num) {
        low.push(num); // 新加入的元素放到low部分
        high.push(low.top()); // 把low堆中最大的元素放到high堆，保证high部分最小的元素比low部分最大的元素大
        low.pop(); // 从low堆弹出顶部元素
        // 经过上述操作，low堆元素没有增加，high堆增加了一个元素
        if(low.size() < high.size()){ //若high堆增加一个元素后，比low堆多一个元素，需要维持平衡
            low.push(high.top()); // 将high中最小的元素放到low中
            high.pop(); //从high堆弹出顶部元素
        }
    }

    double findMedian() {
        return low.size() == high.size() ? 1.0*(low.top() + high.top())/2.0 : low.top();
    }
};
#endif //LEETCODE_MEDIANFINDER_H
