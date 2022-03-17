#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include <linux/perf_event.h>
#include <asm/unistd.h>
#include <time.h>

int len = 1024*128;

static long
perf_event_open(struct perf_event_attr *hw_event, pid_t pid, int cpu,
		        int group_fd, unsigned long flags) {
	int ret;
	ret = syscall(__NR_perf_event_open, hw_event, pid, cpu, group_fd,
			      flags);
	return ret;
}

int main(int argc, char **argv) {
  struct perf_event_attr pe;
  long long count;
  int fd;
  time_t start, end;
  double result;
  float x[len];
  float y[len];
  float z[len];


  memset(&pe, 0, sizeof(pe));
  pe.type = PERF_TYPE_HARDWARE;
  pe.size = sizeof(pe);
  pe.config = PERF_COUNT_HW_CPU_CYCLES;
  pe.disabled = 1;
  pe.exclude_kernel = 1;
  pe.exclude_hv = 1;
  fd = perf_event_open(&pe, 0, -1, -1, 0);
  
  if (fd == -1) {
    fprintf(stderr, "Error opening leader %llx\n", pe.config);
    exit(EXIT_FAILURE);
  }

  ioctl(fd, PERF_EVENT_IOC_RESET, 0);

  std::cout << "0\n";
  for(int i=0; i<len; i++) {
    x[i] = i/3;
    y[i] = (2*i + 1)/3;
	z[i] = 0;
  }
  std::cout << "1\n";

  ioctl(fd, PERF_EVENT_IOC_ENABLE, 0);
  start = clock();
  for(int j=0; j<64; j++) {
	for(int i=0; i<len; i++) {
	  z[i] += x[i] * y[i] + x[i] - y[i];
    }
  }
  ioctl(fd, PERF_EVENT_IOC_DISABLE, 0);
  read(fd, &count, sizeof(count));
  printf("Used %lld cycles\n", count);

  close(fd);
  
  end = clock();

  result = (double)(end - start);
  std::cout.precision(6);
  std::cout << "time taken: " << (result/CLOCKS_PER_SEC) << "s\n";

  return 0;
}
