Task 1 (pdf)
two-pass-assembler-ia32
A two-pass assembler for the 32-bit x86 (IA-32) architecture that translates supported assembly instructions into Little-Endian machine code using opcode, ModR/M, SIB, displacement, and immediate encoding.

Task 2 (valid and invalid instruction)

Roles-

Sanika - 25111008

I worked on the preprocessing part. The preprocess() function takes one assembly line and first removes the comment from it. Then I replace commas with spaces so that it becomes easy to separate the words using stringstream. The first word is taken as the mnemonic and the remaining words are stored in the operands vector. I created the ParsedLine structure to keep the mnemonic and operands together. Finally, I convert both mnemonic and operands to uppercase so that the assembler can accept both capital and small letters. After this, the parsed data is passed to the validators.


Payal - 25111044

I Worked on the mnemonic validation part of the project.Added checks for valid and invalid assembly instructions.Included instructions like MOV, ADD, INC, DEC, MUL, and DIV. Tested the validator with different inputs.Integrated it with the main program for smooth validation.


vaishnavi - 25111013

I worked on the register validation part. The isRegister() function checks whether a given register is one of the supported IA-32 registers such as EAX, EBX, ECX, EDX, ESI, EDI, ESP, and EBP. The checkTwoRegisters() function validates two register operands, while checkOneRegister() validates a single register operand. If an invalid register is provided, an error message is displayed and the validation returns false.


Krishna - 25111003

Worked on valid and invalid instruction validation.
Checked whether the mnemonic/instruction is valid using isValidMnemonic().
Handled instructions like INC, DEC, MUL, and DIV, which require one register.
Handled other instructions that require two registers.
