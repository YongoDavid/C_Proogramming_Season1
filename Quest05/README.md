Welcome to Quest05
In this quest, we dive deep into shell scripting to master commands. Commands like find, globbing, and --exec. This command empowering you to become proficient in manipulating files and directories from the command line.

Task
Task 00: Count Regular Files and Directories Your first challenge is to craft a command line that tallies and displays the count of regular files and directories within the current directory and its subdirectories, inclusive of the starting directory itself (denoted as "."). This command lays the foundation for understanding the structure of the file system. Task 01: Clean Up Unwanted Files In the file named my_clean, your mission is to concoct a command line that scours through the current directory and its subdirectories, hunting down files with names ending in "~" or commencing and concluding with "#". This task sharpens your skills in targeted file search and removal. Task 02: Identify Shell Scripts For your third challenge, you're tasked with devising a command line that ferrets out all filenames, ending with ".sh" across the current directory and its subdirectories. The twist? It should only output the filenames sans the ".sh" extension, showcasing your prowess in precise file manipulation.

Description
To conquer these challenges, we leverage an arsenal of terminal commands tailored to each task's requirements. For Task 00, we employ a combination of find, wc, and ls commands to traverse the directory structure, distinguish between file types, and tally the counts efficiently. Task 01 is tackled using a specialized find command, augmented with -name options to filter out files based on specific patterns, ensuring a thorough cleanup operation. In Task 02, we utilize find again, this time focusing on filenames ending with ".sh". By judiciously applying basename, we extract only the filenames without their ".sh" extensions, streamlining the output for easy consumption.

Installation
No additional packages are required for this project. Simply clone or download the repository from the provided GitHub link to your local machine, and you're all set to explore and practice the challenges at your leisure.

Usage
After downloading the project, navigate to the project directory in your terminal You can and dive into the Quest05 challenges by executing the command lines outlined in the tasks. Experiment, learn, and hone your shell scripting skills to master the art of file manipulation from the command line. Happy coding!