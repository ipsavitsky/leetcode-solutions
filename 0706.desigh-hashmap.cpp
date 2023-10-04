/**
 * @file 0706.desigh-hashmap.cpp
 * @author Ilya Savitsky (ipsavitsky234@gmail.com)
 * @brief https://leetcode.com/problems/design-hashmap/
 * @version 0.1
 * @date 2023-10-04
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <array>
#include <cstdint>
#include <functional>
#include <list>
#include <optional>
#include <tuple>

class MyHashMap {
  private:
    const static std::size_t buckets_cnt = 100;
    std::hash<int> key_hash{};
    using record_t = std::tuple<int, int>;
    using bucket_t = std::list<record_t>;
    using record_it = bucket_t::iterator;
    using hash_t = std::uint64_t;
    std::array<bucket_t, buckets_cnt> buckets;

    std::optional<record_it> get_record(std::size_t hash_i, int key) {
        record_it res = std::find_if(
            this->buckets[hash_i].begin(), this->buckets[hash_i].end(),
            [key](const record_t &cur) { return key == std::get<0>(cur); });
        return res != this->buckets[hash_i].end()
                   ? std::optional<record_it>(res)
                   : std::nullopt;
    }

    inline hash_t calculate_hash_ind(int key) {
        return this->key_hash(key) & (this->buckets_cnt - 1);
    }

  public:
    MyHashMap() {}

    void put(int key, int value) {
        const hash_t hash_i = this->calculate_hash_ind(key);
        auto res = this->get_record(hash_i, key);
        if (res) {
            std::get<1>(**res) = value;
        } else {
            this->buckets[hash_i].push_back({key, value});
        }
    }

    int get(int key) {
        const hash_t hash_i = this->calculate_hash_ind(key);
        auto res = this->get_record(hash_i, key);
        return res ? std::get<1>(**res) : -1;
    }

    void remove(int key) {
        const hash_t hash_i = this->calculate_hash_ind(key);
        auto res = this->get_record(hash_i, key);
        if (res) {
            this->buckets[hash_i].erase(*res);
        }
    }
};
