import os
import datetime
import time
import concurrent.futures

def write_in_file(val):
	fname=open(os.path.join(os.path.split(os.path.realpath(__file__))[0],'file.txt'),'a')
	fname.write(val+'\n')
	fname.close()

def run(t):
	write_in_file(f'{datetime.datetime.now()} -> {t}')
	time.sleep(10)
	return f'{t}{t}'


def main(chk):
	tl=[1,2,3,4,5,6,7,8,9,10,11]
	with concurrent.futures.ProcessPoolExecutor(max_workers=2) as executor:
		results = [executor.submit(run,t) for t in tl]
		for f in concurrent.futures.as_completed(results):
			write_in_file(f'{datetime.datetime.now()} -> {f.result()}')
	return chk+1

if __name__=='__main__':
	chk=0
	while True:
		chk=main(chk)
		write_in_file(f'{datetime.datetime.now()} -> {chk} Iteration completed')
		time.sleep(50)