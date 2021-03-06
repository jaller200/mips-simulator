#pragma once

#include <string>
#include <vector>

#include "instr/instruction.hpp"
#include "instr/instruction_parser.hpp"
#include "types.hpp"

/**
 * A parser for the LA (load address) psuedo-instruction
 */
class LaParser: public InstructionParser {
public:

    // MARK: -- Construction
    LaParser() = default;
    ~LaParser() = default;


    // MARK: -- Parse Methods

    /**
     * Parses a line with the LA (load address) psuedo-instruction
     * 
     * The format for this instruction is as follows:
     * 
     *      LA <Rdest> <label>
     * 
     * A syntax error will be thrown if any of the registers are invalid or
     * out of bounds.
     * 
     * @param line The line to parse
     * @throw SyntaxError If there is a syntax error
     * @return A vector with the instructions
     */
    std::vector<Instruction> parse(const std::string& line) const;
};