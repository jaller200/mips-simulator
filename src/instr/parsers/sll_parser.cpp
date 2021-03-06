
#include "instr/parsers/sll_parser.hpp"

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

// Parses an SLL instruction
std::vector<Instruction> SllParser::parse(const std::string& line) const {
    
    std::vector<Instruction> instructions;

    // First, trim the line and convert to lower case
    std::string trimmedLine = StringUtils::toLowerCase(StringUtils::trim(line));
    if (trimmedLine.length() == 0)
        throw SyntaxError("Invalid Syntax for SLL: Empty input", trimmedLine);

    // Now try to use our regex expression for the form
    //
    //      add dest, src1, imm
    //
    std::regex sll_rgx("^(ori)\\s+(\\$\\w+),\\s*(\\$\\w+),\\s*\\b(0x[0-9a-fA-F]+|0[0-7]*|[1-9][0-9]*|0b[0-1]+)\\b");
    std::smatch match;

    if (!std::regex_search(trimmedLine.cbegin(), trimmedLine.cend(), match, sll_rgx))
        throw SyntaxError("Invalid Syntax for SLL: Invalid format", trimmedLine);

    // Do a quick sanity check for the size (should be exactly 4)
    if (match.size() != 5 || match[1] != "sll")
        throw SyntaxError("Invalid Syntax for SLL: Line does not start with 'ori'", trimmedLine);

    // Now, create our instructions
    sword_t regDest = RegisterBank::getRegister(match[2]);
    sword_t regSrc = RegisterBank::getRegister(match[3]);
    
    // Get our immediate
    word_t imm = 0;
    try {
        imm = static_cast<word_t>(StringUtils::toNumber(match[4]));
    }
    catch (std::exception& e) {
        throw SyntaxError("Invalid Syntax for SLL: Invalid immediate value", trimmedLine);
    }

    if (regDest == -1 || regSrc == -1)
        throw SyntaxError("Invalid Syntax for SLL: Invalid register(s)", trimmedLine);

    if (imm > Instruction::LIMIT_SHAMT)
        throw SyntaxError("Invalid Syntax for SLL: Out of bounds shift amount", trimmedLine);

    // Otherwise, emplace back a new instruction
    Instruction instr;
    instr.setType(InstructionType::R_FORMAT);
    instr.setOpcode(static_cast<word_t>(Opcodes::OPCODE_R_TYPE));
    instr.setRd(regDest);
    instr.setRs(0);
    instr.setRt(regSrc);
    instr.setShamt(imm);
    instr.setFunct(static_cast<word_t>(Functions::FUNCT_SLL));
    instructions.emplace_back(instr);

    return instructions;
}