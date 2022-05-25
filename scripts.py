import os
import re
import sys


TASK_SIGN_NUMBER = 4
PATTERN = "(.+?)\\.(.+?)\\.(.+)"
# replace '#' with number
SEARCH_PATTERN = "(0*#)\\.(.+?)\\.(.+)"


class FileNameParts:
    def __init__(self, number, name, extension, delimeter="."):
        self.number = number
        self.name = name
        self.extension = extension
        self.delimeter = delimeter

    def get_filename(self):
        return self.number + self.delimeter + self.name + self.delimeter + self.extension


class DirectoryDoesNotExistException(Exception):
    pass


def check_question(message):
    result = input(message).strip().lower()
    return (result == "y" or result == "yes" or result == "")

def update_number(string, number):
    if (len(string) < number):
        return '0' * (number - len(string)) + string
    else:
        return string

def get_parts_of_filename(file):
    m = re.search(PATTERN, file)
    if (m is not None):
        number = m.group(1)
        name = m.group(2)
        extension = m.group(3)
        return FileNameParts(number, name, extension)
    else:
        return None

def remove_leading_zeroes(string):
    i = 0
    while (i < len(string) and string[i] == '0'):
        i += 1
    return string[i:]

def update_taskname(string):
    string = string.strip().lower().replace(' ', '-')
    return string

def get_directory_path_or_create(directory, current_path=None):
    if (current_path is None):
        current_path = os.path.abspath(os.getcwd())

    dirpath = os.path.join(current_path, directory)
    if not os.path.exists(dirpath):
        if (not check_question("\nDo you want to create directory (y/n): ")):
            print("\nAborting...")
            return None
        else:
            print("\nCreating directory...")
            os.makedirs(directory)
    return dirpath


def get_files_from_directory(directory, current_path=None):
    if (current_path is None):
        current_path = os.path.abspath(os.getcwd())

    path = os.path.join(current_path, directory)
    if not (os.path.exists(path)):
        raise DirectoryDoesNotExistException(f"Directory '{path}' does not exist.")
    filenames = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    return filenames

def get_directory_path(directory, current_path=None):
    if (current_path is None):
        current_path = os.path.abspath(os.getcwd())

    dirpath = os.path.join(current_path, directory)
    if not os.path.exists(dirpath):
        raise DirectoryDoesNotExistException(f"Directory '{dirpath}' does not exist.")
    return dirpath


def rename():
    # get all files from directory
    current_path = ""  
    # current_path = os.path.abspath(os.getcwd())

    # get files from directory
    directory = input("\nEnter the directory to format: ")
    filenames = get_files_from_directory(directory, current_path)
    dirpath = os.path.join(current_path, directory)
    
    # get number of signs
    number_of_signs = TASK_SIGN_NUMBER
    cnt = input(f"\nEnter number of signs to format (DEFAULT={number_of_signs}): ")
    if (cnt.strip() != ""):
        number_of_signs = int(cnt)

    # create list to update files (without directory)
    rename_pairs = []
    for file in filenames:
         fileparts = get_parts_of_filename(file)
         if (fileparts is not None) and (len(fileparts.number) < number_of_signs):
             fileparts.number = update_number(fileparts.number, number_of_signs)
             # also add directory
             oldfile = os.path.join(dirpath, file)
             newfile = os.path.join(dirpath, fileparts.get_filename())
             rename_pairs.append((oldfile, newfile))
            
    # update filenames
    # get maximum length of file to make print GOOD
    max_length = 0
    for oldfile in [x[0] for x in rename_pairs]:
        if (max_length < len(oldfile)):
            max_length = len(oldfile)

    # ask for update
    if (not len(rename_pairs)):
        print("\nNo files to update...")
        return

    print("\nList of files to update: ")
    for oldfile, newfile in rename_pairs:
        print(oldfile + (" " * (max_length - len(oldfile))) + " -> " + newfile)

    if (not check_question("\nUpdate (y/n): ")):
        print("\nAborting...")
        return

    print("\nUpdating...")
    for oldfile, newfile in rename_pairs:
        os.rename(oldfile, newfile)
        print(newfile)
    input("\nDone...")


def delete_zeroes():
    # get all files from directory
    current_path = ""  
    # current_path = os.path.abspath(os.getcwd())

    # get files from directory
    directory = input("\nEnter the directory to format: ")
    filenames = get_files_from_directory(directory, current_path)
    dirpath = os.path.join(current_path, directory)
    
    # create list to update files (without directory)
    rename_pairs = []
    for file in filenames:
         fileparts = get_parts_of_filename(file)
         if (fileparts is not None) and (fileparts.number != "") and (fileparts.number[0] == '0'):
             fileparts.number = remove_leading_zeroes(fileparts.number)
             # also add directory
             oldfile = os.path.join(dirpath, file)
             newfile = os.path.join(dirpath, fileparts.get_filename())
             rename_pairs.append((oldfile, newfile))
            
    # update filenames
    # get maximum length of file to make print GOOD
    max_length = 0
    for oldfile in [x[0] for x in rename_pairs]:
        if (max_length < len(oldfile)):
            max_length = len(oldfile)

    # ask for update
    if (not len(rename_pairs)):
        print("\nNo files to update...")
        return

    print("\nList of files to update: ")
    for oldfile, newfile in rename_pairs:
        print(oldfile + (" " * (max_length - len(oldfile))) + " -> " + newfile)

    if (not check_question("\nUpdate (y/n): ")):
        print("\nAborting...")
        return

    print("\nUpdating...")
    for oldfile, newfile in rename_pairs:
        os.rename(oldfile, newfile)
        print(newfile)
    input("\nDone.")


def create_task():
    # get directory
    current_path = os.path.abspath(os.getcwd())
    directory = input("\nEnter directory: ").strip()
    dirpath = get_directory_path_or_create(directory, current_path)
    if (dirpath is None):
        return
    else:
        print(dirpath)

    # constructing task
    task_number = input("\nEnter task number: ").strip()

    task_name = input("\nEnter task name: ").strip()
    task_name = update_taskname(task_name)

    task_extension = input("\nEnter task extension: ").strip()

    taskfile = task_number + "." + task_name + "." + task_extension
    taskpath = os.path.join(current_path, directory, taskfile)
    print(taskpath)

    # creating file
    if (os.path.exists(taskpath)):
        print("\nFile already exists")
        if (not check_question("Do you want to rewrite file (y/n): ")):
            print("\nAborting...")
            return

    file = open(taskpath, "w")
    print("\nEnter the content. <C-D> to EOF:")

    # entering the content of file
    input_str = sys.stdin.read()
    file.write(input_str)
    file.flush()
    print("\nDone.", "Characters written:", len(input_str))


def update_task_by_number():
    # create directory if not exists
    current_path = ""
    # current_path = os.path.abspath(os.getcwd())
    directory = input("\nEnter directory: ").strip()
    dirpath = get_directory_path(directory, current_path)

    # constructing task
    task_number = input("\nEnter task number: ").strip()

    # find task by number
    filenames = get_files_from_directory(directory, current_path)
    # regex
    filematch = []
    new_pattern = SEARCH_PATTERN.replace('#', task_number)
    for file in filenames:
        sresult = re.search(new_pattern, file)
        if (sresult is not None):
            filematch.append(file)

    if (len(filematch) == 0):
        print("No files found.")
        print("Aborting...") 
        return
    elif (len(filematch) > 1):
        print("Several files found: ")
        for i in range(len(filematch)):
            print(f"{i + 1}) {filematch[i]}")
        result = int(input("Select one: "))
        taskpath = filematch[result - 1]
    else:
        taskpath = filematch[0]
    taskpath = os.path.join(dirpath, taskpath)
    print("\n" + taskpath) 

    file = open(taskpath, "w")
    print("\nEnter the content. <C-D> to EOF:")

    # entering the content of file
    input_str = sys.stdin.read()
    file.write(input_str)
    file.flush()
    print("\nDone.", "Characters written:", len(input_str))


def menu():
    menu_dict = []
    menu_dict.append({
        "description":"Add zeroes to the number of task", 
        "function": rename
        })
    menu_dict.append({
        "description": "Remove leading zeroes from filename",
        "function": delete_zeroes
        })
    menu_dict.append({
        "description": "Create task file",
        "function": create_task
        })
    menu_dict.append({
        "description": "Update task file by number",
        "function": update_task_by_number
        })

    for i in range(len(menu_dict)):
        print(str(i + 1) + ") " + menu_dict[i]["description"])

    num = int(input("Choose number: "))
    if (num > len(menu_dict)):
        raise ValueError
    else:
        menu_dict[num - 1]["function"]()


def main():
    try:
        menu()
    except (KeyboardInterrupt, ValueError, IndexError, EOFError, DirectoryDoesNotExistException) as e:
        print(str(e))
        print("\nAborting...")


if __name__ == "__main__":
    main()

