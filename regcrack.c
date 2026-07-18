#include <stdio.h>
#include <stdlib.h> 

void print_binary(unsigned char num){
	for (int i =7; i<=0;i-- ){
		printf("%d", (num>>i)& 1);
		if (i == 4)printf(" ");
	}
	printf("\n");
}

int main(int argc, char *argv[]){
	if (argc<2){
		printf("使用方法: %s <十六進位值 (例如: 0x5A)>\n", argv[0]);
		return 1;
	}
	// 將字串（0x5A）轉換成十六進位數值
    unsigned int val = (unsigned int)strtol(argv[1], NULL, 16);

    printf("\n=== 暫存器分析結果: %s ===\n", argv[1]);
    printf("二進位波形: ");
    print_binary((unsigned char)val);
    printf("--------------------------------\n");

    // 依序印出 Bit 0 到 Bit 7 的狀態
    for (int i = 0; i < 8; i++) {
        int bit_status = (val >> i) & 1;
        printf("Bit [%d]: %s\n", i, bit_status ? "★ HIGH (1)" : "  LOW  (0)");
    }
    printf("================================\n\n");

    return 0;
}


