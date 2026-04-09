#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "security.h"

int verify_access(void) {
    // Đọc mã SECRET_TOKEN từ môi trường hệ thống
    char *api_key = getenv("MY_SECRET_TOKEN");

    if (api_key == NULL) {
        printf("Lỗi: Không tìm thấy mã bảo mật (Environment Variable)!\n");
        return 0;
    }

    // Giả sử mã đúng là "HenryNguyen"
    if (strcmp(api_key, "HenryNguyen") == 0) {
        printf("Xác thực thành công! Quyền truy cập được cấp.\n");
        return 1;
    } else {
        printf("Xác thực thất bại! Mã không hợp lệ.\n");
        return 0;
    }
}

#ifdef TEST_MAIN
int main() {
    return verify_access() ? 0 : 1;
}
#endif
