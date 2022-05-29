#include <jni.h>
#include <android_native_app_glue.h>

void
android_main(struct android_app* app)
{
    // main loop
    for (;;)
    {
        int ident;
        int events;
        struct android_poll_source *source;

        // Process this event.
        while ((ident=ALooper_pollAll(0, NULL, &events, (void**)&source)) >= 0)
        {
            if (source != NULL)
            {
                source->process(app, source);
            }
            // Check if we are exiting.
            if (app->destroyRequested != 0) {
                //engine_term_display(&engine);
                return;
            }
        }
    }
}
