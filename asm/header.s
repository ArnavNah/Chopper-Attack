.section .data

.word 0x80371240       /* PI BSB Domain 1 register */
.word 0x0000000F       /* Clockrate setting */
.word 0x80000400       /* Entrypoint address */
.word 0x00001448       /* Revision */
.word 0x214CAD94       /* Checksum 1 */
.word 0xBE1A3B24       /* Checksum 2 */
.word 0x00000000       /* Unknown 1 */
.word 0x00000000       /* Unknown 2 */
.ascii "CHOPPER_ATTACK      " /* Internal name */
.word 0x00000000       /* Unknown 3 */
.word 0x0000004E       /* Cartridge */
.ascii "CH"            /* Cartridge ID */
.ascii "E"             /* Country code */
.byte 0x00             /* Version */
