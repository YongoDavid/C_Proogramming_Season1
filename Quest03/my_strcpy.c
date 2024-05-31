char* my_strcpy(char* dst, char* src) {
    char* mainSrc = dst; 
    while (*src != '\0') {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0'; 
    return mainSrc;
}