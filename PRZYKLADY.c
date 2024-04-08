//1 ################## -- xQueueHandle -- ###############################
float archDataVal[100]={0};
xQueueHandle xDataQueue
xDataQueue = xQueueCreate(100, sizeof(float));
xQueueSend(xDataQueue, (void * ) &Channels[channelNumber].value, 0);
while (uxQueueMessagesWaiting(xDataQueue) > 0)
{
	xQueueReceive(xDataQueue, &archDataVal[queueDataSize], 0);
	queueDataSize++;
}

int queueSize = uxQueueMessagesWaiting(xMessageQueue);
for (int i = 0; i < queueSize; i++)
{
	uxQueueMessagesWaiting(xMessageQueue);
	if (xQueueReceive(xMessageQueue, &(eventArchMessage), portMAX_DELAY))
	{
		...
		uxQueueMessagesWaiting(xMessageQueue);
	}
}


xQueueReset(xDataQueue);

void ARCHIVE_SendEvent(char* eventDesc)
{
	char* eventMessage = pvPortMalloc(100);
	if (NULL == eventMessage)
	{

	}
	else
	{
		strncpy(eventMessage,eventDesc,100);
		if(pdPASS != xQueueSend(xMessageQueue, &eventMessage, 20))
			vPortFree(eventMessage);
	}
}

//2 ################## -- xQueueHandle -- ###############################
xSemaphoreHandle xSemaphoreChannels;
uint32_t TakeChannelsMutex(uint32_t timeout)
{
	if(xSemaphoreTake( xSemaphoreChannels, timeout) == pdTRUE)
		return 1;
	else
		return 0;
}
void GiveChannelsMutex(void)
{
	xSemaphoreGive(xSemaphoreChannels);
}
if (TakeChannelsMutex(100)){}

//3 ########################## - continue - ############################
for (int i = 0; i < 16; i++)
{
	if(i==7)
		continue;
}
//4 #####################
