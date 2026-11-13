with open('rom/chopper_attack.z64', 'rb') as f:
    rom = f.read()

import re
data = rom[0x67100:0x7C1B0]
for m in re.finditer(rb'[\x20-\x7E]{4,}', data):
    print(f'Offset 0x{0x67100 + m.start():06X}: {m.group().decode("ascii", "ignore")}')
