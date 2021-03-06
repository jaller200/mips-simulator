
#include "instr/parsers/bne_parser.hpp"

#include <iostream>
#include <regex>
#include <sstream>

#include "exception/syntax_error.hpp"
#include "instr/functions.hpp"
#include "instr/instruction.hpp"
#include "instr/instruction_type.hpp"
#include "instr/opcodes.hpp"
#include "registers/register_bank.hpp"
#include "utils/string_utils.hpp"

// MARK: -- Parse Methods

// Parses a BNE instruction
std::vector<Instruction> BneParser::parse(const std::string& line) const {
    
    std::vector<Instruction> instructions;

    // First, trim the line and convert to lower case
    std::string trimmedLine = StringUtils::toLowerCase(StringUtils::trim(line));
    if (trimmedLine.length() == 0)
        throw SyntaxError("Invalid Syntax for BNE: Empty input", trimmedLine);

    // Now try to use our regex expression for the form
    //
    //      beq dest, src, label
    //
    std::regex bne_rgx("^(bne)\\s+(\\$\\w+),\\s*(\\$\\w+),\\s*(\\w+)");
    std::smatch match;

    if (!std::regex_search(trimmedLine.cbegin(), trimmedLine.cend(), match, bne_rgx))
        throw SyntaxError("Invalid Syntax for BNE: Invalid format", trimmedLine);

    // Do a quick sanity check for the size (should be exactly 4)
    if (match.size() != 5 || match[1] != "bne")
        throw SyntaxError("Invalid Syntax for BNE: Line does not start with 'bne'", trimmedLine);

    // Now, create our instructions
    sword_t regDest = RegisterBank::getRegister(match[2]);
    sword_t regSrc = RegisterBank::getRegister(match[3]);
    std::string label = match[4];

    if (regDest == -1 || regSrc == -1)
        throw SyntaxError("Invalid Syntax for BNE: Invalid register(s)", trimmedLine);

    // Otherwise, emplace back a new instruction
    Instruction instr;
    instr.setType(InstructionType::I_FORMAT);
    instr.setOpcode(static_cast<word_t>(Opcodes::OPCODE_BNE));
    instr.setRs(regSrc);
    instr.setRt(regDest);
    instr.setLabel(label);
    instructions.emplace_back(instr);

    return instructions;
}