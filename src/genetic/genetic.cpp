#include "genetic.h"
#include "src/generator/mask_generator.h"
#include "src/solver/force_brute_solver.h"
#include "data/consts.h"

#include <vector>
#include <memory>
#include <limits>
#include <random>
#include <algorithm>

const uint8_t population_size = 100u;
const uint8_t no_solvable_rank = 100u; 

struct LifeForm {
    std::shared_ptr<Mask> mask;
    uint8_t rank;

    LifeForm(const Mask& new_mask) {
        mask = std::make_shared<Mask>(new_mask);
        rank = std::numeric_limits<uint8_t>::max();
    }

    LifeForm& operator=(LifeForm& life_form) {
        if (this != &life_form){
            mask = life_form.mask;
            rank = life_form.rank;
        }
        
        return *this;
    }
};

Mask Genetic::operate(const Board& board, uint8_t qtd_hint) {
    std::vector<LifeForm> current_generation;
    std::vector<LifeForm> new_generation;

    new_generation.reserve(population_size);

    for (uint8_t i = 0u; i < population_size; i++) {
        new_generation.push_back(LifeForm{MaskGenerator::generate(3, qtd_hint)});
    }

    do {
        if (!current_generation.empty()) {
            new_generation.clear();
            new_generation.reserve(population_size);

            for (uint8_t i = 0u; i < population_size; i++) {
                const uint8_t parent0 = rand() % population_size;
                const uint8_t parent1 = rand() % population_size;

                Mask new_mask = current_generation[parent0].mask->mix(*current_generation[parent1].mask);
                uint8_t new_qtd_hints = new_mask.count_hints();

                // If has more or less hints quantity, remove or add hints
                if (new_qtd_hints > qtd_hint) {
                    while (new_qtd_hints > qtd_hint)
                    {
                        const uint8_t remove_cell_line = rand() % COLUMN_SIZE;
                        const uint8_t remove_cell_column = rand() % LINE_SIZE;
                        const Hint hint_limit{remove_cell_line, remove_cell_column};

                        if (new_mask.remove_hint_lower_bound(hint_limit) || new_mask.remove_hint_upper_bound(hint_limit)) {
                            new_qtd_hints--;
                        }
                    }
                } else if (new_qtd_hints < qtd_hint) {
                    while (new_qtd_hints < qtd_hint)
                    {
                        const uint8_t new_cell_line = rand() % COLUMN_SIZE;
                        const uint8_t new_cell_column = rand() % LINE_SIZE;
                        const Hint new_hint{new_cell_line, new_cell_column};

                        if (new_mask.insert_hint(new_hint)) {
                            new_qtd_hints++;
                        }
                    }
                }

                new_generation.push_back(new_mask);
            }
        }

        current_generation = new_generation;

        // Classify masks
        std::for_each(std::begin(current_generation), std::end(current_generation), [&](LifeForm& life_form){
            Board classify_board = board.apply_mask(*life_form.mask);

            Solvability solvability = ForceBruteSolver::resolve(classify_board);

            if (solvability == Solvability::NO_SOLVABLE) {
                life_form.rank = no_solvable_rank;
            } else {
                
            }
        });

    } while (current_generation.front().rank = 0u);

    return *current_generation.front().mask;
}