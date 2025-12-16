#include <vector>
#include <cstdint>
#include <iostream>

class Table {
public:
    Table(size_t seed);

    uint8_t operator()(size_t i, size_t j) const;
    uint8_t& operator()(size_t i, size_t j);

    friend std::ostream& operator<< (std::ostream& os, const Table& t);

private:
    std::vector<uint8_t> _table;

    void generate_3x3(size_t i, size_t j);
    bool generate_9x9(size_t i, size_t j);
    
    bool check_line(size_t i, size_t j, uint8_t value);
    bool check_column(size_t i, size_t j, uint8_t value);
    bool check_box(size_t i, size_t j, uint8_t value);
    bool check_pos(size_t i, size_t j, uint8_t value);
};

std::ostream& operator<< (std::ostream& os, const Table& t);