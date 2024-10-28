#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <fstream>
#include <memory>

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

template <typename K, typename V>
class KVStore {
private:
    std::vector<std::pair<K, V>> data;

public:
    // 插入键值对
    void insert(const K& key, const V& value) {
        // 尝试找到键是否已存在
        auto it = std::find_if(data.begin(), data.end(),
                               [key](const std::pair<K, V>& p) { return p.first == key; });
        if (it != data.end()) {
            // 如果键已存在，更新值
            it->second = value;
        } else {
            // 如果键不存在，添加新的键值对
            data.emplace_back(key, value);
        }
    }

    // 获取值
    bool get(const K& key, V& value) const {
        auto it = std::find_if(data.begin(), data.end(),
                               [key](const std::pair<K, V>& p) { return p.first == key; });
        if (it != data.end()) {
            value = it->second;
            return true;
        }
        return false;
    }

    // 删除键值对
    bool remove(const K& key) {
        auto it = std::find_if(data.begin(), data.end(),
                               [key](const std::pair<K, V>& p) { return p.first == key; });
        if (it != data.end()) {
            data.erase(it);
            return true;
        }
        return false;
    }

    // 获取存储的大小
    size_t size() const {
        return data.size();
    }
};