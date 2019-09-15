void ShowVersionMessages() {
  const char compiledate[] = __DATE__ ;
  const char compiletime[] = __TIME__ ;
  Serial.println("*****************************************************");
  Serial.printf("Program Name: %s\n", ProgramName);
  Serial.printf("Author: %s\n", Author);
  Serial.printf("Contact: %s\n", AuthorContact);
  Serial.printf("Compiled: %s %s\n", compiledate, compiletime);
  Serial.println("*****************************************************");
}
