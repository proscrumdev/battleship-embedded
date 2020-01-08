#param (
#    [Parameter(Mandatory=$true)]
#    [String] $binPath
#)

#esptool.py --chip esp32 --before default_reset --after hard_reset write_flash -z --flash_mode dio --flash_freq 40m --flash_size detect 0x1000 C:\Users\ThomasSchissler\.platformio\packages\framework-arduinoespressif32\tools\sdk\bin\bootloader_dio_40m.bin 0x8000 $binPath\partitions.bin 0xe000 C:\Users\ThomasSchissler\.platformio\packages\framework-arduinoespressif32\tools\partitions\boot_app0.bin 0x10000 $binPath\firmware.bin

param (
    [Parameter(Mandatory=$true)]
    [String] $binPath
)

esptool.py `
    --chip esp32 `
    --before default_reset `
    --after hard_reset `
    write_flash `
    -z `
    --flash_mode dio `
    --flash_freq 40m `
    --flash_size detect `
    0x8000 $binPath/partitions.bin `
    0x10000 $binPath/firmware.bin

    #   0x1000 $binPath\bootloader_dio_40m.bin `
 #   0xe000 $binPath\boot_app0.bin `
 