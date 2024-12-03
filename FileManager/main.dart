import 'dart:io';

void main() {
  while (true) {
    print('\n=== Simple File Manager ===');
    print('1. List files in a directory');
    print('2. Read a file');
    print('3. Create a new file');
    print('4. Exit');
    stdout.write('Enter your choice: ');

    String? choice = stdin.readLineSync();

    switch (choice) {
      case '1':
        listFiles();
        break;
      case '2':
        readFile();
        break;
      case '3':
        createFile();
        break;
      case '4':
        print('Exiting the file manager. Goodbye!');
        exit(0);
      default:
        print('Invalid choice. Please try again.');
    }
  }
}

void listFiles() {
  stdout.write('Enter the directory path: ');
  String? dirPath = stdin.readLineSync();

  if (dirPath != null) {
    Directory dir = Directory(dirPath);

    if (dir.existsSync()) {
      List<FileSystemEntity> files = dir.listSync();
      print('\nFiles in $dirPath:');
      for (var file in files) {
        print(file.path);
      }
    } else {
      print('The directory does not exist.');
    }
  }
}

void readFile() {
  stdout.write('Enter the file path: ');
  String? filePath = stdin.readLineSync();

  if (filePath != null) {
    File file = File(filePath);

    if (file.existsSync()) {
      String content = file.readAsStringSync();
      print('\nContent of $filePath:\n$content');
    } else {
      print('The file does not exist.');
    }
  }
}

void createFile() {
  try {
    stdout.write('Enter the file path to create: ');
    String? filePath = stdin.readLineSync();

    if (filePath != null) {
      File file = File(filePath);

      if (file.existsSync()) {
        print('The file already exists.');
      } else {
        stdout.write('Enter content for the file: ');
        String? content = stdin.readLineSync();
        file.writeAsStringSync(content ?? '');
        print('File created at $filePath.');
      }
    }
  } on FileSystemException catch (e) {
    print('Error creating file: ${e}');
  } on IOException catch (e) {
    print('Error reading or writing file: $e');
  } catch (e) {
    print('An unexpected error occurred: $e');
  } 
}

