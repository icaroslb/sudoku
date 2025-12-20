#include "mask.h"
#include "data/consts.h"

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <algorithm>

const Hint middle{MIDDLE_BOARD_LINE, MIDDLE_BOARD_COLUMN};

Mask::Mask() {}

Mask::Mask(const Mask& mask) : _hints(mask._hints) {}

Mask& Mask::operator=(const Mask& mask) {
    if (this != &mask) {
        _hints = mask._hints;
    }

    return *this;
}

std::set<Hint>::iterator Mask::begin() {
    return std::begin(_hints);
}

const std::set<Hint>::iterator Mask::begin() const {
    return std::begin(_hints);
}

std::set<Hint>::iterator Mask::end() {
    return std::end(_hints);
}

const std::set<Hint>::iterator Mask::end() const {
    return std::end(_hints);
}

bool Mask::insert_hint(const Hint& hint) {
    return _hints.insert(hint).second;
}

std::set<Hint>::iterator Mask::find_hint_lower_bound(const Hint& hint) const {
    return _hints.lower_bound(hint);
}

std::set<Hint>::iterator Mask::find_hint_upper_bound(const Hint& hint) const {
    return _hints.upper_bound(hint);
}

bool Mask::remove_hint_lower_bound(const Hint& hint){
    const auto lower_bound = find_hint_lower_bound(hint);
    bool is_removed = false;

    if (lower_bound != std::end(_hints)) {
        _hints.erase(lower_bound);
        is_removed = true;
    }

    return is_removed;
}

bool Mask::remove_hint_upper_bound(const Hint& hint){
    const auto upper_bound = find_hint_upper_bound(hint);
    bool is_removed = false;

    if (upper_bound != std::end(_hints)) {
        _hints.erase(upper_bound);
        is_removed = true;
    }

    return is_removed;
}

uint8_t Mask::count_hints() const {
    return _hints.size();
}

Mask Mask::mix(const Mask& mask) const {
    const Hint middle_hint{MIDDLE_BOARD_LINE, MIDDLE_BOARD_COLUMN};
    Mask new_mask{};

    auto hints0 = find_hint_lower_bound(middle_hint)++;
    auto hints1 = mask.find_hint_upper_bound(middle_hint);

    do {
        hints0--;
        new_mask.insert_hint(*hints0);
    } while (hints0 != std::begin(_hints));

    while (hints1 != std::end(mask._hints)) {
        new_mask.insert_hint(*hints1);
        hints1++;
    }

    return new_mask;
}