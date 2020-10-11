int main()
{
int sockfd,maxseg,sendbuff,optlen;
if((sockfd=socket(AF_INET,SOCK_STREAM,0))<0)
{
perror(“socket”);
exit(0);
}
optlen=sizeof(maxseg);
if(getsockopt(sockfd,IPPROTO_TCP,TCP_MAXSEG,(char *)&maxseg,&optlen)<0)
{
perror(“get sockopt1”);
exit(0);
}
printf(“\n TCP maxseg=%d”,maxseg);
sendbuff=12324;
if(setsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char *)&sendbuff,sizeof(sendbuff))<0)
{
perror(“set socketopt”);
exit(0);
}
optlen=sizeof(sendbuff);
if(getsockopt(sockfd,SOL_SOCKET,SO_SNDBUF,(char *)&sendbuff,&optlen)<0)
{
perror(“getsockopt2”);
exit(0);
}
printf(“\n send buffer size=%d\n”,sendbuff);
}
