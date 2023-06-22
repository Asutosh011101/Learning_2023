#include <stdio.h>

struct Time {
   int hours;
   int minutes;
   int seconds;
};

// Calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time start, struct Time end) {
   struct Time diff;

   // Convert the time periods to seconds
   int startTimeInSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
   int endTimeInSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;

   // Calculate the difference in seconds
   int diffInSeconds = endTimeInSeconds - startTimeInSeconds;

   // Convert the difference back to hours, minutes, and seconds
   diff.hours = diffInSeconds / 3600;
   diffInSeconds %= 3600;
   diff.minutes = diffInSeconds / 60;
   diff.seconds = diffInSeconds % 60;

   return diff;
}

int main() {
   struct Time start, end, difference;

   printf("Enter the start time period (hours minutes seconds): ");
   scanf("%d %d %d", &start.hours, &start.minutes, &start.seconds);

   printf("Enter the end time period (hours minutes seconds): ");
   scanf("%d %d %d", &end.hours, &end.minutes, &end.seconds);

   difference = calculateTimeDifference(start, end);

   printf("Difference: %d hours %d minutes %d seconds\n", difference.hours, difference.minutes, difference.seconds);

   return 0;
}
