#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <algorithm> 
#include <vector>
#include <mutex>
#include <iostream>
#include <string>
#include <utility> // for std::pair

template <typename K, typename V>
class ArrayList {
private:
    std::vector<std::pair<K, V>> _list;
    std::mutex _mtx;

public:
    ArrayList() {}

    ~ArrayList() {}

    // Insert or update a key-value pair
    void insert_element(const K& key, const V& value) {
        std::lock_guard<std::mutex> lock(_mtx);
        auto it = std::find_if(_list.begin(), _list.end(), [&key](const std::pair<K, V>& p) {
            return p.first == key;
        });

        if (it != _list.end()) {
            // Key exists, update the value
            it->second = value;
        } else {
            // Key does not exist, insert the key-value pair
            _list.emplace_back(key, value);
        }
    }

    // Search/get for a value by key
    bool search_element(const K& key, V& value) {
        std::lock_guard<std::mutex> lock(_mtx);
        auto it = std::find_if(_list.begin(), _list.end(), [&key](const std::pair<K, V>& p) {
            return p.first == key;
        });

        if (it != _list.end()) {
            value = it->second;
            return true;
        }

        return false;
    }

    // Delete a key-value pair by key
    void delete_key(const K& key) {
        std::lock_guard<std::mutex> lock(_mtx);
        auto it = std::find_if(_list.begin(), _list.end(), [&key](const std::pair<K, V>& p) {
            return p.first == key;
        });

        if (it != _list.end()) {
            _list.erase(it);
        }
    }

    // Display all key-value pairs
    void display_list() {
        std::lock_guard<std::mutex> lock(_mtx);
        for (const auto& pair : _list) {
            std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
        }
    }

    // Get the size of the list
    size_t size() {
        std::lock_guard<std::mutex> lock(_mtx);
        return _list.size();
    }
};



#endif // ARRAYLIST_H