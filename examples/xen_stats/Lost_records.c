#include <stdio.h>

#include "Event.h"
#include "EventHandler.h"
#include "Macros.h"
#include "Trace.h"
#include "Num_Events.h" 
#include "Num_Exceptions.h" 
#include "Num_Exceptions_in_xen.h" 
#include "Num_Interrupts.h"
#include "Num_Interrupts_in_xen.h"
#include "Num_Hypercalls.h"
#include "Lost_records.h"

int lost_records_init(EventHandler *handler)
{
	return SUCCESS;
}

int lost_records_handler(EventHandler *handler, Event *event)
{
	/* Lost records received. Clear all handler data */
	if((event->ns - event->lastNs) > LOST_REC_MAX_TIME)
	{
		num_events_reset();
		num_exceptions_reset();
		num_exceptions_in_xen_reset();
		num_interrupts_reset();
		num_interrupts_in_xen_reset();
		num_hypercalls_reset();
	}
	return SUCCESS;
}

int lost_records_finalize(EventHandler *handler)
{
	return SUCCESS;
}

struct EventHandler lostRecordsHandler = 
{
	.name = "lost_records",
	.event_id = TRC_LOST_RECORDS,
	.init = lost_records_init,
	.data = (void *)NULL,
	.process_event = lost_records_handler,
	.finalize = lost_records_finalize,
};
