from random import randint
from tqdm import tqdm
from os import path


TOTAL_TEST_FILES = 41
MIN_NUM_DATA = 100000
MAX_NUM_DATA = 1000000
MAX_VALUE_ABS = 100000
MIN_CACHE_SIZE = 2
MAX_CACHE_SIZE = 1000
TEST_DIR = "tests"

def gen_one_test(filename: str):
    with open(path.join(TEST_DIR, test_file_name), "w") as test_file:
        num_data = randint(MIN_NUM_DATA, MAX_NUM_DATA)
        cache_size = randint(MIN_CACHE_SIZE, MAX_CACHE_SIZE)
        test_file.write(f"{cache_size} {num_data} ")

        for _ in range(num_data):
            test_file.write(f"{randint(-MAX_VALUE_ABS, MAX_VALUE_ABS)} ")
    

if __name__ == "__main__":
    print (f"Generating {TOTAL_TEST_FILES} tests in {TEST_DIR}...")
    for test_idx in tqdm(range(TOTAL_TEST_FILES)):
        test_file_name = f"{test_idx}.test"
        
        gen_one_test(test_file_name)
