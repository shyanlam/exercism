#include "knapsack.h"
#include <algorithm>
#include <cassert>
#include <iomanip>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <set>
namespace knapsack {

// TODO: add your solution here
    using row_t = std::vector<int>;
    using table_t = std::vector<row_t>;

    std::string centered(size_t width, const std::string& str) {
        if (str.length() < width) {
            size_t padding = width - str.size();
            auto r_pad = padding / 2;
            auto l_pad = padding - r_pad;
            if (l_pad > r_pad)
                std::swap(l_pad, r_pad);
            return std::string(l_pad, ' ') + str + std::string(r_pad, ' ');
        } else {
            return str;
        }
    }
    template <typename T>
    std::string centered(size_t width, const T& t) {
        return centered(width, std::to_string(t));
    }

    struct print_table_t {
        // Item/Weight   | 0 | 1 | ... | max_weight 
        // ===========================================
        //  Empty        | 0 | 0 | ... |      0
        // --------------------------------------------
        // W:<w1> V:<v1> |   |   | ... |       
        // W:<w2> V:<v2> |   |   | ... |       

        const int max_weight{};
        const std::string corner{ "Item\\Weight " };
        size_t row_label_width{};
        std::vector<std::string> row_labels{};
        std::vector<std::string> col_labels{};
        size_t col_width{};
        size_t table_width{};

        print_table_t(int max_weight_, const std::vector<Item>& items);
        void print_header_row(std::ostream& os) const;
        void print_row_data(std::ostream& os, const table_t& table, size_t row) const;
        void print_table(std::ostream& os, const table_t& table) const;
    };

    static std::string to_string(const Item& item) {
        return "W:" + std::to_string(item.weight) + " V:" + std::to_string(item.value);
    }

    print_table_t::print_table_t(int max_weight_, const std::vector<Item>& items)
        : max_weight(max_weight_)
        , row_label_width(corner.size())
        , row_labels(items.size() + 1)
        , col_labels(max_weight+1)
    {
        const size_t row_count = items.size() + 1;

        for (const auto& item : items) {
            col_width = std::max(col_width, std::max(std::to_string(item.weight).length(), std::to_string(item.value).length()));
        }
        table_width = row_label_width + 1 + (col_width + 1) * (max_weight + 1);

        for (size_t w = 0; w < col_labels.size(); ++w) {
            col_labels[w] = centered(col_width, w);
        }

        for (size_t r = 0; r < row_count; ++r) {
            if (r == 0)
                row_labels[0] = "Empty ";
            else 
                row_labels[r] = to_string(items[r-1]) + " ";
            row_label_width = std::max(row_label_width, row_labels[r].size());
        }
    }

    void print_table_t::print_header_row(std::ostream& os) const {
        os << std::setw(row_label_width) << corner << "|";
        for (const auto& col_label : col_labels) {
            os << centered(col_width, col_label) << "|";
        }
        // header divider
        os << std::endl;
        os << std::string(table_width, '=') << std::endl;
    }

    void print_table_t::print_row_data(std::ostream& os, const table_t& table, size_t rowNo) const {
        // row header
        os << std::setw(row_label_width) << row_labels[rowNo] << "|";
        // row data
        const auto& row = table[rowNo];
        for (size_t c{ 0 }; c < row.size(); ++c) {
            os << centered(col_width, row[c]) << "|";
        }
        os << std::endl;
        if (rowNo == 0)
            os << std::string(table_width, '-') << std::endl;
    }

    void print_table_t::print_table(std::ostream& os, const table_t& table) const {

        // header row
        print_header_row(os);

        // row data
        for (size_t r{ 0 }; r < table.size(); ++r) {
            print_row_data(os, table, r);
        }
        os << std::endl;
    }

    std::map<int, Item> get_item_taken(const int max_weight, const std::vector<Item>& items, const std::vector<std::vector<int>>& table) {
        std::map<int, Item> item_taken{};
        assert(table.size() == items.size() + 1);
        int col = max_weight;
        for (size_t row = items.size(); row > 0; --row) {
            int value = table[row][col];
            int prev_value = table[row - 1][col];
            if (value != prev_value) {
                item_taken[row] = items[row-1];
                col -= items[row-1].weight;
            }
        }
        return item_taken;
    }

    int maximum_value(int max_weight, const std::vector<Item>& items) {
        if (max_weight == 0 || items.size() == 0)
            return 0;

        //std::cout << "\n\nNEW ANALYSIS " << std::string(80, '=') << std::endl << std::endl;
        table_t table{ items.size() + 1, row_t(max_weight + 1, 0)};
        print_table_t print_table(max_weight, items);
        int row{ 1 };
        for (const auto& item : items) {
            for (int w = 0; w <= max_weight; ++w) {
                if (w < item.weight) {
                    table[row][w] = table[row-1][w];
                } else {
                    const int cur_best = table[row - 1][w];
                    const int prev_item = w >= item.weight ? table[row - 1][w - item.weight] : 0;
                    table[row][w] = std::max(item.value + prev_item, cur_best);
                }
            }
            //print_table.print_table(std::cout, table);
            ++row;
        }
        //std::cout << std::endl << "Final table" << std::endl;
        //print_table.print_table(std::cout, table);

        const int best = table.back().back();
        std::cout << "Best value: " << best << std::endl;
        std::map<int, Item> item_taken = get_item_taken(max_weight, items, table);
        std::cout << "Item(s) taken:" << std::endl;
        if (item_taken.empty()) {
            std::cout << "\t" << "None." << std::endl;
        } else {
            int total_weight{ 0 }, total_value{ 0 };
            for (auto [row, item] : item_taken) {
                std::cout << "\t" << to_string(item) << std::endl;
                total_weight += item.weight;
                total_value += item.value;
            }
            std::cout << "Total weight: " << total_weight << ", total value: " << total_value << std::endl;
        }
        std::cout << std::endl;
        return best;
    }

}  // namespace knapsack
