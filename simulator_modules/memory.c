
#include "memory.h"
#include "cJSON.h"
#include "stdint.h"
#include "string.h"
#include <assert.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "mTaskDef.h"
#include "FreeRTOS.h"

char *path_in_windows = "./simulator_files";

/**
 * save information into the SD card using a save_cb function
 */
int32_t memory_save_file(void (*save_cb)(void))
{
	int32_t ret = 0;

    save_cb();

	return ret;
}

/** memory load json from file
 * given a file name it retrieves the json string and passes it to the parser
 * before it free's the json string and closes the file
 * @param file_name the absolute path to the file
 * @param parser a json_parser of type
 * @return -2 if it could not open the file or the result of the parser otherwise
 */
int32_t memory_load_json_from_file(char *file_name, json_parser parser)
{
	int32_t ret = 0;
	char file_path[256];
	snprintf(file_path, 256, "%s/%s", path_in_windows, file_name);

	FILE *stream;

	int32_t BUFFER_SIZE = 10;
	char *json_txt = malloc(BUFFER_SIZE);
	char buffer[BUFFER_SIZE];
	int32_t numread = 0;

	// Open for write
	if ((fopen_s(&stream, file_path, "r+t")) == 0) // C4996
	{
		printf("The file '%s' was opened\n", file_path);

		if (fgets(json_txt, BUFFER_SIZE, stream) != NULL)
		{
			numread = BUFFER_SIZE;
			printf("first characters: %s", json_txt);

			while (fgets(buffer, BUFFER_SIZE, stream) != NULL)
			{
				numread += BUFFER_SIZE;
				char *temp = malloc(numread);
				snprintf(temp, numread, "%s%s", json_txt, buffer);
				free(json_txt);
				json_txt = temp;
			}
		}

		printf("number of characters read %d", numread);
		printf("############### CONTENT ################\n\n\n");
		printf(json_txt);
		printf("############### CONTENT END ################\n\n\n");

		ret = parser(json_txt);
		free(json_txt);
		// Close stream if it is not NULL
		if (fclose(stream))
		{
			printf("The file '%s' was not closed\n", file_path);
			ret = 1;
		}
	}
	else
	{
		printf("The file %s was not opened", file_path);
		ret = 2;
	}

	// All other files are closed:
	int32_t numclosed = _fcloseall();
	printf("Number of files closed by _fcloseall: %u\n", numclosed);
	return ret;
}

int32_t memory_save_json_to_file(char *file_name, cJSON *head)
{

	char *json_txt = cJSON_Print(head);
	assert(json_txt);
	uint32_t file_size = strlen(json_txt);
	char file_path[256];

	snprintf(file_path, 256, "%s/%s", path_in_windows, file_name);

	FILE *stream;

	// Open for write
	if ((fopen_s(&stream, file_path, "w+")) == 0) // C4996
	{
		printf("The file '%s' was opened\n", file_path);
		if (fwrite(json_txt, sizeof(char), file_size, stream) != file_size)
		{
			printf("Failed to write\n");
		}
		// Close stream if it is not NULL
		if (fclose(stream))
		{
			printf("The file '%s' was not closed\n", file_path);
			return 1;
		}
	}
	else
	{
		printf("The file %s was not opened", file_path);
	}

	free(json_txt);

	return 0;
}

int32_t memory_delete_file(char *file_name)
{
	int32_t ret = 0;
    char file_path[256];

	snprintf(file_path, 256, "%s/%s", path_in_windows, file_name);

	ret = remove(file_path);

	return ret;
}

/** memory directory count file
 * This function counts the number of files in a directory and returns the number of files it found
 * if the directory cannot be opened it returns -1
 * @param directory_path the path of the directory
 * @return the number of files, -1 if the directory cannot be opened
 */
int32_t memory_directory_count_files(char *directory_path)
{
	struct dirent *pDirent;
	DIR *pDir;

	int32_t ret = 0;

	char abs_directory_path[256];
	snprintf(abs_directory_path, 256, "%s/%s", path_in_windows, directory_path);
	// Ensure we can open directory.

	pDir = opendir(abs_directory_path);
	if (pDir != NULL)
	{
		while ((pDirent = readdir(pDir)) != NULL)
		{
			printf("[%s]\n", pDirent->d_name);
			if (pDirent->d_name[0] == '.')
			{
				// ignore dot entries
			}
			else
			{
				++ret;
			}
		}
	}
	else
	{
		printf("Cannot open directory '%s'\n", directory_path);
	}

	// Close directory and exit.

	closedir(pDir);
	return ret;
}

/** memory directory count file
 * This function expects a list of size the amount of files in the directory and fills that list
 * with the absolute file paths of the files in that directory
 * @param directory_path the path of the directory
 * @param list the list in which the file paths should be saved
 * @param list_element_max_size the size of the elements in the list
 * @return 1 if everything is fine, -1 if the directory could not be opened, -2 if a file path was longer than element max size
 */
int32_t memory_directory_get_filenames(char *directory_path, char **list,
                                       int32_t list_element_max_size)
{

	struct dirent *pDirent;
	DIR *pDir;

	int32_t file_counter = 0;
	int32_t ret = 1;

	// Ensure we can open directory.

    char abs_directory_path[256];
	snprintf(abs_directory_path, 256, "%s/%s", path_in_windows, directory_path);
	// Ensure we can open directory.

	pDir = opendir(abs_directory_path);
    if (pDir != NULL)
	{
		while ((pDirent = readdir(pDir)) != NULL)
		{
			printf("[%s]\n", pDirent->d_name);
			if (pDirent->d_name[0] == '.')
			{
				// ignore dot entries
			}
			else
			{
				int32_t path_size =
				    snprintf(list[file_counter++], list_element_max_size,
				             "%s/%s", directory_path, pDirent->d_name);
				if (path_size > list_element_max_size)
				{
					ret = -2;
				}
			}
		}
	}
	else
	{
		printf("Cannot open directory '%s'\n", directory_path);
	}

	// Close directory and exit.

	closedir(pDir);
	return ret;
}
