main()
{
	if(fork()) {
		printf("Parent waiting for child to terminate\n");
		wait(2);
	} else
		sleep(2);
	return 0;
}
