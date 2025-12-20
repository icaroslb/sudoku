#ifndef MASK_H
#define MASK_H

#include "hint.h"

#include <set>
#include <cstdint>
#include <ostream>

class Mask {
public:
    Mask();
    Mask(const Mask& mask);

    Mask& operator=(const Mask& mask);

    /**
     * Returns begin set hint iterator
     * @return Begin set hint iterator
     */
    std::set<Hint>::iterator begin();

    /**
     * Returns begin iterator
     * @return Begin iterator
     */
    const std::set<Hint>::iterator begin() const;

    /**
     * Returns end set hint iterator
     * @return End set hint iterator
     */
    std::set<Hint>::iterator end();

    /**
     * Returns end iterator
     * @return End iterator
     */
    const std::set<Hint>::iterator end() const;

    /**
     * Insert new hint
     * @param hint New hint to be inserted
     * @return True if hint was inserted, false if already exists
     */
    bool insert_hint(const Hint& hint);

    /**
     * Finds the lower bound hint from param hint
     * @param hint The limit hint
     * @return Lower bound iterator
     */
    std::set<Hint>::iterator find_hint_lower_bound(const Hint& hint) const;

    /**
     * Finds the upper bound hint from param hint
     * @param hint The limit hint
     * @return Uppter bound iterator
     */
    std::set<Hint>::iterator find_hint_upper_bound(const Hint& hint) const;

    /**
     * Removes the lower bound hint from param hint
     * @param hint The limit hint
     * @return True if any hint was removed, false otherwise
     */
    bool remove_hint_lower_bound(const Hint& hint);

    /**
     * Removes the upper bound hint from param hint
     * @param hint The limit hint
     * @return True if any hint was removed, false otherwise
     */
    bool remove_hint_upper_bound(const Hint& hint);

    /**
     * Returns the quantity of hints
     * @return The quantity of hints
     */
    uint8_t count_hints() const;

    /**
     * Returns a mask with values mixed
     * @param mask Mask to get values mixed
     * @return Mask with values mixed
     */
    Mask mix(const Mask& mask) const;

private:
    std::set<Hint> _hints;
};

#endif // MASK_H