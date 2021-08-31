# USBHotPlugProgramming
Getting the skill of working with hot-plugging USB devices using the universal cross-platform libusb interface.

План:
1. Создать функцию обратного вызова (callback) с кодом реакции на подключение нового устройства
2. Выполнить инициализацию библиотеки libusb
3. Зарегистрировать функцию обратного вызова
4. Ожидать возникновение события на USB шине
5. Отменить регистрацию функции обратного вызова
6. Выполнить деинициализацию библиотеки libusb
