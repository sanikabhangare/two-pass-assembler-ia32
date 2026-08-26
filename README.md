Task 1 (pdf)
two-pass-assembler-ia32
A two-pass assembler for the 32-bit x86 (IA-32) architecture that translates supported assembly instructions into Little-Endian machine code using opcode, ModR/M, SIB, displacement, and immediate encoding.

Task 2 (valid and invalid instruction)

Roles-

Sanika - 25111008

I worked on the preprocessor part of the assembler. I handled the parsing of assembly instructions by separating the mnemonic and operands, removing comments and handling commas. I also added uppercase conversion so that instructions and registers can be processed consistently.


Payal - 25111044

I worked on adding and validating assembly instruction mnemonics and their corresponding opcodes.I added instruction details such as MOV, ADD, SUB, CMP, XOR, OR, and AND.I also implemented operand count validation for different instructions.I connected the mnemonic validation with the opcode.txt file.I helped ensure that valid instructions and operands are correctly identified.


vaishnavi - 25111013

I worked on the register validation part. The isRegister() function checks whether a given register is one of the supported IA-32 registers such as EAX, EBX, ECX, EDX, ESI, EDI, ESP, and EBP. The checkTwoRegisters() function validates two register operands, while checkOneRegister() validates a single register operand. If an invalid register is provided, an error message is displayed and the validation returns false.


Krishna - 25111003

Worked on valid and invalid instruction validation.
Checked whether the mnemonic/instruction is valid using isValidMnemonic().
Handled instructions like INC, DEC, MUL, and DIV, which require one register.
Handled other instructions that require two registers.
