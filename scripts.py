import os
import re
import sys


TASK_SIGN_NUMBER = 4
PATTERN = "(.+?)\\.(.+?)\\.(.+)"


class FileNameParts:
    def __init__(self, number, name, extension, delimeter="."):
        self.number = number
        self.name = name
        self.extension = extension
        self.delimeter = delimeter

    def get_filename(self):
        return self.number + self.delimeter + self.name + self.delimeter + self.extension


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


def rename():
    # get all files from directory
    current_path = ""  
    # current_path = os.path.abspath(os.getcwd())

    directory = input("Enter the directory to format: ")
    path = os.path.join(current_path, directory)
    filenames = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    
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
             oldfile = os.path.join(path, file)
             newfile = os.path.join(path, fileparts.get_filename())
             rename_pairs.append((oldfile, newfile))
            
    # update filenames
    # get maximum length of file to make print GOOD
    max_length = 0
    for oldfile in [x[0] for x in rename_pairs]:
        if (max_length < len(oldfile)):
            max_length = len(oldfile)

    # ask for update
    if (len(rename_pairs)):
        print("\nList of files to update: ")
        for oldfile, newfile in rename_pairs:
            print(oldfile + (" " * (max_length - len(oldfile))) + " -> " + newfile)

        result = input("\nUpdate (y/n): ").strip().lower()
        if (len(result) and (result == "y" or result == "yes")):
            result = True
        else:
            print("\nAborting...")
            result = False

        if (result is True):
            print("\nUpdating...")
            for oldfile, newfile in rename_pairs:
                os.rename(oldfile, newfile)
                print(newfile)
            input("\nDone...")
    else:
        print("\nNo files to update...")


def remove_leading_zeroes(string):
    i = 0
    while (i < len(string) and string[i] == '0'):
        i += 1
    return string[i:]


def delete_zeroes():
    # get all files from directory
    current_path = ""  
    # current_path = os.path.abspath(os.getcwd())

    directory = input("Enter the directory to format: ")
    path = os.path.join(current_path, directory)
    filenames = [f for f in os.listdir(path) if os.path.isfile(os.path.join(path, f))]
    
    # create list to update files (without directory)
    rename_pairs = []
    for file in filenames:
         fileparts = get_parts_of_filename(file)
         if (fileparts is not None) and (fileparts.number != "") and (fileparts.number[0] == '0'):
             fileparts.number = remove_leading_zeroes(fileparts.number)
             # also add directory
             oldfile = os.path.join(path, file)
             newfile = os.path.join(path, fileparts.get_filename())
             rename_pairs.append((oldfile, newfile))
            
    # update filenames
    # get maximum length of file to make print GOOD
    max_length = 0
    for oldfile in [x[0] for x in rename_pairs]:
        if (max_length < len(oldfile)):
            max_length = len(oldfile)

    # ask for update
    if (len(rename_pairs)):
        print("\nList of files to update: ")
        for oldfile, newfile in rename_pairs:
            print(oldfile + (" " * (max_length - len(oldfile))) + " -> " + newfile)

        result = input("\nUpdate (y/n): ").strip().lower()
        if (len(result) and (result == "y" or result == "yes")):
            result = True
        else:
            print("\nAborting...")
            result = False

        if (result is True):
            print("\nUpdating...")
            for oldfile, newfile in rename_pairs:
                os.rename(oldfile, newfile)
                print(newfile)
            input("\nDone...")
    else:
        print("\nNo files to update...")


def update_taskname(string):
    string = string.strip().lower().replace(' ', '-')
    return string


def create_task():
    # create directory if not exists
    current_path = os.path.abspath(os.getcwd())
    directory = input("\nEnter directory: ").strip()
    dirpath = os.path.join(current_path, directory)
    if not os.path.exists(dirpath):
        print("Creating directory...")
        os.makedirs(directory)
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
        result = input("Do you want to rewrite file (y/n): ").strip().lower()
        if not (len(result) and (result == "y" or result == "yes")):
            print("Aborting...")
            return

    file = open(taskpath, "w")
    print("\nEnter the content. <C-D> to EOF:")

    # entering the content of file
    input_str = sys.stdin.read()
    file.write(input_str)
    print("\nDone.")
    file.flush()


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

    for i in range(len(menu_dict)):
        print(str(i + 1) + ") " + menu_dict[i]["description"])

    num = int(input("Choose number: "))
    if (num > len(menu_dict)):
        raise ValueError
    else:
        menu_dict[num - 1]["function"]()


def main():
    menu()


if __name__ == "__main__":
    try:
        main()
    except (KeyboardInterrupt, ValueError):
        print("\nAborting...")


